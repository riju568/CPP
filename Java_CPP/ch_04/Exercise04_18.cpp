#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.18 (Student major and status) Write a program that prompts the user to enter two
 * characters and displays the major and status represented in the characters. The first
 * character indicates the major and the second is number character 1, 2, 3, 4, which
 * indicates whether a student is a freshman, sophomore, junior, or senior. Suppose
 * the following characters are used to denote the majors:
 * M: Mathematics
 * C: Computer Science
 * I: Information Technology
 * Here is a sample run:
 * Enter two characters: M1
 * Mathematics Freshman
 * Enter two characters: C3
 * Computer Science Junior
 * Enter two characters: T3
 * Invalid input
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter two characters: ";
        std::string input;
        if (!(std::cin >> input))
        {
            std::cout << "Invalid input\n";
            return EXIT_SUCCESS;
        }

        if (input.length() != 2)
        {
            std::cout << "Invalid input\n";
            return EXIT_SUCCESS;
        }

        char major_char = static_cast<char>(std::toupper(static_cast<unsigned char>(input[0])));
        char status_char = input[1];

        std::string_view major;
        switch (major_char)
        {
        case 'M':
            major = "Mathematics";
            break;
        case 'C':
            major = "Computer Science";
            break;
        case 'I':
            major = "Information Technology";
            break;
        default:
            std::cout << "Invalid input\n";
            return EXIT_SUCCESS;
        }

        std::string_view status;
        switch (status_char)
        {
        case '1':
            status = "Freshman";
            break;
        case '2':
            status = "Sophomore";
            break;
        case '3':
            status = "Junior";
            break;
        case '4':
            status = "Senior";
            break;
        default:
            std::cout << "Invalid input\n";
            return EXIT_SUCCESS;
        }

        std::cout << major << ' ' << status << '\n';

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}