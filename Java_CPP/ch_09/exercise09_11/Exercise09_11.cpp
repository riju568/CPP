#include <iostream>
#include <cstdlib>
#include <exception>

/**
 * Write a test program that prompts the user to enter a, b, c, d, e, and f and
 * displays the result. If ad minus bc is 0, report that "The equation has
 * no solution."
 */


class LinearEquation {
private:
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;

public:
    LinearEquation(double a, double b, double c, double d, double e, double f)
        : a(a), b(b), c(c), d(d), e(e), f(f) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getD() const { return d; }
    double getE() const { return e; }
    double getF() const { return f; }

    bool isSolvable() const {
        return (a * d - b * c) != 0;
    }

    double getX() const {
        return (e * d - b * f) / (a * d - b * c);
    }

    double getY() const {
        return (a * f - e * c) / (a * d - b * c);
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        double a, b, c, d, e, f;

        std::cout << "Enter values for a, b, c, d, e, and f now:\n";

        if (!(std::cin >> a >> b >> c >> d >> e >> f)) {
            return EXIT_FAILURE;
        }

        LinearEquation tester(a, b, c, d, e, f);

        if (tester.isSolvable()) {
            std::cout << "x is " << tester.getX() << '\n';
            std::cout << "y is " << tester.getY() << '\n';
        } else {
            std::cout << "The equation has no solution\n";
        }

        return EXIT_SUCCESS;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}