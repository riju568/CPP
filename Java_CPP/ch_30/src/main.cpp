#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <thread>
#include <atomic>
#include <chrono>
#include <exception>
#include <memory>
#include <iostream>


class CarPanel : public wxPanel {
private:
    double baseX = 0.0;
    double baseY = 200.0;
    std::atomic<int> sleepTime{50};
    std::atomic<bool> isSuspended{false};
    std::atomic<bool> isRunning{true};
    std::thread animationThread;
public:
    explicit CarPanel(wxWindow* parent)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE) {
        SetBackgroundStyle(wxBG_STYLE_PAINT);
        Bind(wxEVT_PAINT, &CarPanel::OnPaint, this);
        Bind(wxEVT_KEY_DOWN, &CarPanel::OnKeyDown, this);
        Bind(wxEVT_LEFT_DOWN, &CarPanel::OnMouseDown, this);
        Bind(wxEVT_LEFT_UP, &CarPanel::OnMouseUp, this);
        animationThread = std::thread([this]() { RunLoop(); });
    }
    ~CarPanel() override {
        isRunning = false;
        if (animationThread.joinable()) {
            animationThread.join();
        }
    }

    void Suspend() noexcept { isSuspended = true; }
    void Resume() noexcept { isSuspended = false; }
    void Faster() noexcept { if (sleepTime > 1) --sleepTime; }
    void Slower() noexcept { ++sleepTime; }

private:
    void RunLoop() {
        try {
            while (isRunning) {
                if (!isSuspended) {
                    CallAfter([this]() {
                        MoveCar();
                        Refresh();
                    });
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime.load()));
            }
        } catch (const std::exception& e) {
            wxLogError("Animation Thread standard exception: %s", e.what());
        } catch (...) {
            wxLogError("Animation Thread non-standard exception occurred.");
        }
    }

    void MoveCar() noexcept {
        int w, h;
        GetClientSize(&w, &h);
        baseY = h;

        if (baseX > w) {
            baseX = -50.0;
        } else {
            baseX += 1.0;
        }
    }

    void OnPaint(wxPaintEvent& WXUNUSED(event)) {
        wxAutoBufferedPaintDC dc(this);
        dc.Clear();
        dc.SetBrush(*wxBLACK_BRUSH);
        dc.SetPen(*wxBLACK_PEN);
        dc.DrawCircle(wxPoint(static_cast<int>(baseX + 15), static_cast<int>(baseY - 5)), 5);
        dc.DrawCircle(wxPoint(static_cast<int>(baseX + 35), static_cast<int>(baseY - 5)), 5);
        dc.SetBrush(*wxGREEN_BRUSH);
        dc.SetPen(*wxGREEN_PEN);
        dc.DrawRectangle(static_cast<int>(baseX), static_cast<int>(baseY - 20), 50, 10);
        dc.SetBrush(*wxRED_BRUSH);
        dc.SetPen(*wxRED_PEN);
        wxPoint points[4];
        points[0] = wxPoint(static_cast<int>(baseX + 10), static_cast<int>(baseY - 20));
        points[1] = wxPoint(static_cast<int>(baseX + 20), static_cast<int>(baseY - 30));
        points[2] = wxPoint(static_cast<int>(baseX + 30), static_cast<int>(baseY - 30));
        points[3] = wxPoint(static_cast<int>(baseX + 40), static_cast<int>(baseY - 20));
        dc.DrawPolygon(4, points);
    }

    void OnKeyDown(wxKeyEvent& event) {
        switch (event.GetKeyCode()) {
            case WXK_UP:
                Faster();
                break;
            case WXK_DOWN:
                Slower();
                break;
            default:
                event.Skip();
                break;
        }
    }

    void OnMouseDown(wxMouseEvent& event) {
        Suspend();
        event.Skip();
    }

    void OnMouseUp(wxMouseEvent& event) {
        Resume();
        event.Skip();
    }
};

class MainFrame : public wxFrame {
public:
    MainFrame() : wxFrame(nullptr, wxID_ANY, "Exercise30_02 - Racing Car", wxDefaultPosition, wxSize(250, 250)) {
        CarPanel* panel = new CarPanel(this);
        panel->SetFocus();
    }
};

class RacingCarApp : public wxApp {
public:
    bool OnInit() override {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        try {
            MainFrame* frame = new MainFrame();
            frame->Show(true);
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Initialization standard exception: " << e.what() << '\n';
            return false;
        } catch (...) {
            std::cerr << "Initialization non-standard exception occurred.\n";
            return false;
        }
    }
};

wxIMPLEMENT_APP(RacingCarApp);