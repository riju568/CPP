#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <exception>

struct Ball {
    double x;
    double y;
    double dx;
    double dy;
    double radius;

    Ball(double x_val, double y_val, double radius_val, double dx_val = 1.0, double dy_val = 1.0)
        : x(x_val), y(y_val), dx(dx_val), dy(dy_val), radius(radius_val) {}
};

class CollidingBallSimulator {
private:
    std::vector<Ball> balls;
    double width;
    double height;
    bool is_paused;
    std::mt19937 rng;

    bool check_overlap(const Ball& b1, const Ball& b2) const {
        double dist_sq = (b1.x - b2.x) * (b1.x - b2.x) + (b1.y - b2.y) * (b1.y - b2.y);
        double rad_sum = b1.radius + b2.radius;
        return dist_sq <= (rad_sum * rad_sum);
    }

public:
    CollidingBallSimulator(double w = 450.0, double h = 350.0)
        : width(w), height(h), is_paused(false), rng(std::random_device{}()) {}

    void add_ball() {
        std::uniform_real_distribution<double> dist_dir(-2.0, 2.0);
        double dx = dist_dir(rng);
        double dy = dist_dir(rng);
        if (dx == 0) dx = 1.0;
        if (dy == 0) dy = 1.0;

        balls.emplace_back(30.0, 30.0, 20.0, dx, dy);
        std::cout << "Added ball #" << balls.size() << " (Radius: 20.0)\n";
    }

    void remove_ball() {
        if (!balls.empty()) {
            balls.pop_back();
            std::cout << "Removed latest ball. Remaining count: " << balls.size() << "\n";
        } else {
            std::cout << "No balls to remove.\n";
        }
    }
    void pause() {
        is_paused = true;
        std::cout << "Simulation suspended.\n";
    }
    void resume() {
        is_paused = false;
        std::cout << "Simulation resumed.\n";
    }
    void step_simulation() {
        if (is_paused) {
            std::cout << "Simulation is suspended. Resume to step.\n";
            return;
        }
        for (auto& ball : balls) {
            if (ball.x - ball.radius < 0 || ball.x + ball.radius > width) {
                ball.dx *= -1.0;
            }
            if (ball.y - ball.radius < 0 || ball.y + ball.radius > height) {
                ball.dy *= -1.0;
            }
            ball.x += ball.dx;
            ball.y += ball.dy;
        }
        for (size_t i = 0; i < balls.size(); ++i) {
            for (size_t j = i + 1; j < balls.size(); ) {
                if (check_overlap(balls[i], balls[j])) {
                    std::cout << "Collision detected between ball #" << (i + 1) 
                              << " and ball #" << (j + 1) << "!\n";
                    balls[i].radius += balls[j].radius; // Merge radius
                    std::cout << "Ball #" << (i + 1) << " new radius: " << balls[i].radius << "\n";
                    balls.erase(balls.begin() + j); // Erase later added ball
                } else {
                    ++j;
                }
            }
        }
    }

    void remove_at_click(double click_x, double click_y) {
        auto it = std::remove_if(balls.begin(), balls.end(), [&](const Ball& b) {
            double dist_sq = (click_x - b.x) * (click_x - b.x) + (click_y - b.y) * (click_y - b.y);
            return dist_sq <= (b.radius * b.radius);
        });

        if (it != balls.end()) {
            std::cout << "Removed " << std::distance(it, balls.end()) << " ball(s) at (" 
                      << click_x << ", " << click_y << ").\n";
            balls.erase(it, balls.end());
        } else {
            std::cout << "No ball hit at (" << click_x << ", " << click_y << ").\n";
        }
    }

    void display_status() const {
        std::cout << "\n--- Ball Simulator Status (" << (is_paused ? "SUSPENDED" : "RUNNING") << ") ---\n";
        std::cout << "Total Balls: " << balls.size() << "\n";
        for (size_t i = 0; i < balls.size(); ++i) {
            std::cout << "  Ball #" << (i + 1) << " -> Pos: (" << balls[i].x << ", " << balls[i].y 
                      << "), Radius: " << balls[i].radius << "\n";
        }
        std::cout << "----------------------------------------\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        CollidingBallSimulator sim;
        std::cout << "Colliding Bouncing Balls Simulator\n";
        std::cout << "Commands:\n";
        std::cout << "  +         : Add a ball\n";
        std::cout << "  -         : Remove latest ball\n";
        std::cout << "  s         : Step simulation forward 1 frame\n";
        std::cout << "  p         : Suspend simulation\n";
        std::cout << "  r         : Resume simulation\n";
        std::cout << "  c x y     : Target removal at (x, y)\n";
        std::cout << "  i         : Display status info\n";
        std::cout << "  q         : Quit\n\n";

        char cmd;
        while (std::cout << "Enter command: " && std::cin >> cmd) {
            if (cmd == '+') {
                sim.add_ball();
            } else if (cmd == '-') {
                sim.remove_ball();
            } else if (cmd == 's' || cmd == 'S') {
                sim.step_simulation();
                sim.display_status();
            } else if (cmd == 'p' || cmd == 'P') {
                sim.pause();
            } else if (cmd == 'r' || cmd == 'R') {
                sim.resume();
            } else if (cmd == 'c' || cmd == 'C') {
                double x, y;
                if (std::cin >> x >> y) {
                    sim.remove_at_click(x, y);
                } else {
                    std::cin.clear();
                    std::string dummy;
                    std::cin >> dummy;
                    std::cout << "Invalid coordinates.\n";
                }
            } else if (cmd == 'i' || cmd == 'I') {
                sim.display_status();
            } else if (cmd == 'q' || cmd == 'Q') {
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