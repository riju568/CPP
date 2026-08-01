#include <iostream>
#include <string>
#include <exception>

void displayPermutation(const std::string& s1, const std::string& s2)
{
    if (!s2.empty())
    {
        for (std::size_t i = 0; i < s2.length(); ++i)
        {
            std::string shuffle1 = s1 + s2[i];
            std::string shuffle2 = s2.substr(0, i) + s2.substr(i + 1);
            displayPermutation(shuffle1, shuffle2);
        }
    }
    else
    {
        std::cout << s1 << '\n';
    }
}

void displayPermutation(const std::string& s)
{
    displayPermutation("", s);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a string: ";
        std::string input;

        if (!(std::cin >> input))
        {
            throw std::runtime_error("Failed to read string input.");
        }

        displayPermutation(input);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}