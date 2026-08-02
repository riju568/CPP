#include <iostream>
#include <cmath>
#include <exception>
#include <memory>

class ClockPane {
private:
    int hour;
    int minute;
    int second;
    double w;
    double h;

public:
    ClockPane(int h_val, int m_val, int s_val, double width = 250.0, double height = 250.0)
        : hour(h_val), minute(m_val), second(s_val), w(width), h(height) {}

    void computeHands() {
        double clockRadius = std::min(w, h) * 0.8 * 0.5;
        double centerX = w / 2.0;
        double centerY = h / 2.0;
        const double pi = 3.14159265358979323846;

        double sLength = clockRadius * 0.8;
        double secondX = centerX + sLength * std::sin(second * (2.0 * pi / 60.0));
        double secondY = centerY - sLength * std::cos(second * (2.0 * pi / 60.0));

        std::cout << "Clock [Hour: " << hour << ", Min: " << minute << ", Sec: " << second << "]\n";
        std::cout << " - Second hand endpoint: (" << secondX << ", " << secondY << ")\n";
    }
};

int main() {
    try {
        auto clock1 = std::make_unique<ClockPane>(4, 20, 45);
        auto clock2 = std::make_unique<ClockPane>(22, 46, 15);

        clock1->computeHands();
        clock2->computeHands();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception.\n";
        return 2;
    }
    return 0;
}