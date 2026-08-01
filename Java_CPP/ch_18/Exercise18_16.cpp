#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <exception>


int count(std::string_view chars, std::size_t high)
{
    if (chars.empty())
    {
        return 0;
    }

    // Safely cast char to unsigned char to avoid UB in std::isupper
    int isUpper = std::isupper(static_cast<unsigned char>(chars[high])) ? 1 : 0;

    if (high == 0)
    {
        return isUpper;
    }

    return isUpper + count(chars, high - 1);
}


int count(std::string_view chars)
{
    if (chars.empty())
    {
        return 0;
    }
    return count(chars, chars.length() - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a list of characters in one line: ";
        std::string line;
        
        if (!std::getline(std::cin, line))
        {
            throw std::runtime_error("Failed to read input line.");
        }

        std::cout << "The number of uppercase letters in the list is: " 
                  << count(line) << '\n';
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