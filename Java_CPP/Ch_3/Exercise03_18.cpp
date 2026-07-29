#include <iostream>
#include <string>
#include <stdexcept>
/**
 * *3.18 (Cost of shipping) A shipping company uses the following function to
 * calculate the cost (in dollars) of shipping based on the weight of the
 * package (in pounds). c(w) = d 3.5, if 0 5.5, if 1 8.5, if 3 10.5, if 10 666
 * 6www w666 ===6 =131020
 * <p>
 * Write a program that prompts the user to enter the weight of the package and
 * display the shipping cost. If the weight is greater than 50, display a
 * message “the package cannot be shipped.”
 * */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter your package's weight: ";
        double weight = 0.0;
        if (!(std::cin >> weight))
        {
            throw std::runtime_error("Invalid input: Please enter a valid numeric weight.");
        }

        if (weight > 50.0)
        {
            std::cout << "The package cannot be shipped.\n";
            return 0;
        }

        std::string shipping = "";

        if (weight > 0 && weight <= 1)
        {
            shipping += "3.5";
        }
        else if (weight > 1 && weight <= 3)
        {
            shipping += "5.5";
        }
        else if (weight > 3 && weight <= 10)
        {
            shipping += "8.5";
        }
        else if (weight > 10 && weight <= 20)
        {
            shipping += "10.5";
        }

        std::cout << "With a package weight of " << weight << " your cost of shipping will be " << shipping << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}