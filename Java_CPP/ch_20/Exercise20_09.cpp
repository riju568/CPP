#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <exception>
#include <stdexcept>

struct Ball {
    double x;
    double y;
    double radius;

    Ball(double x_val, double y_val, double r) 
        : x(x_val), y(y_val), radius(r) {}
};

class MultiBallManager {
private:
    std::vector<Ball> balls;
    std::mt19937 rng;

public:
    MultiBallManager() : rng(std::random_device{}()) {}

    void add_ball() {
        std::uniform_real_distribution<double> dist_radius(2.0, 20.0);
        double radius = dist_radius(rng);
        balls.emplace_back(30.0, 30.0, radius);
        std::cout << "Added ball with radius: " << radius << '\n';
    }

    void remove_largest_ball() {
        if (balls.empty()) {
            std::cout << "No balls to remove.\n";
            return;
        }

        // Find ball with maximum radius
        auto max_it = std::max_element(balls.begin(), balls.end(),
            [](const Ball& a, const Ball& b) {
                return a.radius < b.radius;
            });

        std::cout << "Removed largest ball with radius: " << max_it->radius << '\n';
        balls.erase(max_it);
    }

    void print_state() const {
        std::cout << "\nCurrent ball count: " << balls.size() << "\nRadii: ";
        for (const auto& ball : balls) {
            std::cout << ball.radius << " ";
        }
        std::cout << "\n";
    }

    size_t count() const {
        return balls.size();
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        MultiBallManager manager;
        std::cout << "Multi-Ball Command Interface:\n";
        std::cout << "  '+' : Add ball (random radius 2 to 20)\n";
        std::cout << "  '-' : Remove one of largest balls\n";
        std::cout << "  'l' : List active balls\n";
        std::cout << "  'q' : Quit program\n\n";

        char choice;
        while (std::cout << "Enter command: " && std::cin >> choice) {
            if (choice == '+') {
                manager.add_ball();
            } else if (choice == '-') {
                manager.remove_largest_ball();
            } else if (choice == 'l' || choice == 'L') {
                manager.print_state();
            } else if (choice == 'q' || choice == 'Q') {
                break;
            } else {
                std::cout << "Unknown command.\n";
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}