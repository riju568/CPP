#include <wx/wx.h>
#include <asio.hpp>
#include <thread>
#include <sstream>
#include <iomanip>

using asio::ip::tcp;

constexpr double KILOGRAMS_PER_POUND = 0.45359237;
constexpr double METERS_PER_INCH = 0.0254;

struct BmiDto {
    double weight;
    double height;
};

std::string ProcessBmi(double weightPounds, double heightInches) {
    double weightKg = weightPounds * KILOGRAMS_PER_POUND;
    double heightM = heightInches * METERS_PER_INCH;
    double bmi = weightKg / (heightM * heightM);

    std::string category = "Obese";
    if (bmi < 18.5) category = "Underweight";
    else if (bmi < 25.0) category = "Normal";
    else if (bmi < 30.0) category = "Overweight";

    std::ostringstream ss;
    ss << "BMI is " << std::fixed << std::setprecision(2) << bmi << ". " << category << ". ";
    return ss.str();
}


class ServerFrame : public wxFrame {
public:
    wxTextCtrl* logArea;

    ServerFrame() : wxFrame(nullptr, wxID_ANY, "Exercise31_02Server", wxDefaultPosition, wxSize(450, 200)) {
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        logArea = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
        sizer->Add(logArea, 1, wxEXPAND | wxALL, 5);
        SetSizer(sizer);
        std::thread([this]() { RunServer(); }).detach();
    }

private:
    void RunServer() {
        try {
            asio::io_context io_context;
            tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8000));

            wxQueueEvent(logArea->GetEventHandler(), new wxThreadEvent());
            logArea->CallAfter([this]() {
                logArea->AppendText("Exercise31_02Server started...\n");
            });

            while (true) {
                tcp::socket socket(io_context);
                acceptor.accept(socket);
                BmiDto dto;
                asio::read(socket, asio::buffer(&dto, sizeof(BmiDto)));
                std::string result = ProcessBmi(dto.weight, dto.height);
                asio::write(socket, asio::buffer(result));

                logArea->CallAfter([this, result]() {
                    logArea->AppendText("Connected to a client.\n" + result + "\n");
                });
            }
        } catch (std::exception& e) {
            std::string err = e.what();
            logArea->CallAfter([this, err]() {
                logArea->AppendText("Server Error: " + err + "\n");
            });
        }
    }
};

class ClientFrame : public wxFrame {
    wxTextCtrl* txtWeight;
    wxTextCtrl* txtHeight;
    wxTextCtrl* displayLog;

public:
    ClientFrame() : wxFrame(nullptr, wxID_ANY, "Exercise31_02Client", wxDefaultPosition, wxSize(560, 300)) {
        wxPanel* panel = new wxPanel(this);
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxFlexGridSizer* grid = new wxFlexGridSizer(2, 3, 5, 5);

        grid->Add(new wxStaticText(panel, wxID_ANY, "Weight in pounds:"));
        txtWeight = new wxTextCtrl(panel, wxID_ANY, "");
        grid->Add(txtWeight);
        grid->AddSpacer(0);

        grid->Add(new wxStaticText(panel, wxID_ANY, "Height in inches:"));
        txtHeight = new wxTextCtrl(panel, wxID_ANY, "");
        grid->Add(txtHeight);

        wxButton* btnSubmit = new wxButton(panel, wxID_ANY, "Submit");
        grid->Add(btnSubmit);

        displayLog = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

        mainSizer->Add(grid, 0, wxALL | wxEXPAND, 10);
        mainSizer->Add(displayLog, 1, wxALL | wxEXPAND, 10);
        panel->SetSizer(mainSizer);

        btnSubmit->Bind(wxEVT_BUTTON, &ClientFrame::OnSubmit, this);
    }

private:
    void OnSubmit(wxCommandEvent& evt) {
        try {
            double weight = std::stod(std::string(txtWeight->GetValue().mb_str()));
            double height = std::stod(std::string(txtHeight->GetValue().mb_str()));

            asio::io_context io_context;
            tcp::socket socket(io_context);
            socket.connect(tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 8000));

            BmiDto dto{ weight, height };
            asio::write(socket, asio::buffer(&dto, sizeof(BmiDto)));

            char buf[128] = { 0 };
            size_t len = socket.read_some(asio::buffer(buf));

            displayLog->AppendText("Weight: " + std::to_string(weight) + "\n");
            displayLog->AppendText("Height: " + std::to_string(height) + "\n");
            displayLog->AppendText(std::string(buf, len) + "\n");

        } catch (std::exception& ex) {
            displayLog->AppendText(std::string("Error: ") + ex.what() + "\n");
        }
    }
};

// Entry Point launching both Server and Client windows
class BmiApp : public wxApp {
public:
    virtual bool OnInit() {
        ServerFrame* server = new ServerFrame();
        server->Show(true);

        ClientFrame* client = new ClientFrame();
        client->Show(true);

        return true;
    }
};

wxIMPLEMENT_APP(BmiApp);