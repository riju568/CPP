#include <iostream>
#include <cstdlib>
#include <exception>


//|_____________________________UML Diagram_____________________________________|
/*																				|
 * 					   		   Linear Equation							   	    |
 * _____________________________________________________________________________|
 * 																				|
 *      -a:double																|
 *      -b:double    									           				|
 * 	    -c:double		  														|
 * 	    -d:double		                                            			|
 * 		-e:double																|
 * 		-f:double																|
 * _____________________________________________________________________________|
 *		LinearEquation(double:a,double:b,double:c,double:d,double:e,double:f)	|
 *		getA(): void															|
 *		getB(): void															|
 *		getC(): void															|
 *		getD(): void															|
 *		getE(): void															|
 *		getF(): void															|
 *		isSolvable(): boolean													|
 * 		getCenterX(): double															|
 * 		getCenterY(): double															|
 * 																				|
 *______________________________________________________________________________*/


/**
 * Exercise 9.11 (Algebra: 2 � 2 linear equations) Design a class
 * named LinearEquation for a 2 � 2 system of linear equations:
 * <p>
 * <p>
 * The class contains:
 * <p>
 * Private data fields a, b, c, d, e, and f.
 * <p>
 * A constructor with the arguments for a, b, c, d, e, and f.
 * <p>
 * Six getter methods for a, b, c, d, e, and f.
 * <p>
 * A method named isSolvable() that returns true if ad minus bc is not 0.
 * <p>
 * <p>
 * Methods getCenterX() and getCenterY() that return the solution for the equation.
 * <p>
 * Draw the UML diagram for the class and then implement the class.
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