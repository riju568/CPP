#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <exception>


//|_______________________UML Diagram________________________|
/*														   	 |
 * 			   		  QuadraticEquation		        		 |
 * __________________________________________________________|
 * 												   		     |
 *        			- a:double                               |
 * 	   	 			- b:double                               |
 * 	   	 			- c:double                               |
 * __________________________________________________________|
 *		QuadraticEquation(a:double,b:double,c:double)	     |
 *		getRoot1(): double								     |
 * 	    getRoot2(): double								     |
 *		getDiscriminant(): double							 |
 * 		getA(): double										 |
 * 		getB(): double										 |
 * 		getC(): double  ss									 |
 * 															 |
 *___________________________________________________________*/


/**
 * *9.10 (Algebra: quadratic equations) Design a class named QuadraticEquation for
 * a quadratic equation ax2 + bx + x = 0. The class contains:
 * ■ Private data fields a, b, and c that represent three coefficients.
 * ■ A constructor for the arguments for a, b, and c.
 * ■ Three getter methods for a, b, and c.
 * ■ A method named getDiscriminant() that returns the discriminant, which is
 * b2 - 4ac.
 * ■ The methods named getRoot1() and getRoot2() for returning two roots of
 * the equation
 * r1 = -b + Sqrt(b^2 - 4ac) / 2a
 * r2 = -b - Sqrt(b2 - 4ac) / 2a
 * These methods are useful only if the discriminant is non-negative. Let these methods return 0 if the discriminant
 * is negative.
 * <p>
 * Draw the UML diagram for the class and then implement the class.
 */


class QuadraticEquation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    double getC() const {
        return c;
    }

    double getDiscriminant() const {
        return (b * b) - (4.0 * a * c);
    }

    double getRoot1() const {
        double discriminant = getDiscriminant();
        if (discriminant < 0) {
            return 0.0;
        }
        return (-b + std::sqrt(discriminant)) / (2.0 * a);
    }

    double getRoot2() const {
        double discriminant = getDiscriminant();
        if (discriminant < 0) {
            return 0.0;
        }
        return (-b - std::sqrt(discriminant)) / (2.0 * a);
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter values for a, b, and c:\n";

        double a, b, c;
        if (!(std::cin >> a >> b >> c)) {
            return EXIT_FAILURE;
        }

        QuadraticEquation quadraticEquation(a, b, c);

        double discriminant = quadraticEquation.getDiscriminant();

        std::cout << "The discriminant value is " 
                  << std::fixed << std::setprecision(2) << discriminant;

        if (discriminant > 0) {
            std::cout << " and the two root values are: ";
            std::cout << std::fixed << std::setprecision(5) << quadraticEquation.getRoot1();
            std::cout << "  ";
            std::cout << std::fixed << std::setprecision(5) << quadraticEquation.getRoot2() << '\n';
        } 
        else if (discriminant == 0) {
            std::cout << " and the one root value is: ";
            std::cout << std::defaultfloat << quadraticEquation.getRoot1() << "(Root 1)\n";
        } 
        else {
            std::cout << " The equation has no roots.\n";
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