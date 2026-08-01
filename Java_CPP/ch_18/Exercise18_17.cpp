#include <iostream>
#include <string>
#include <string_view>
#include <exception>


int count(std::string_view chars, char ch, std::size_t high)
{
    if (chars.empty())
    {
        return 0;
    }

    int match = (chars[high] == ch) ? 1 : 0;

    if (high == 0)
    {
        return match;
    }

    return match + count(chars, ch, high - 1);
}

int count(std::string_view chars, char ch)
{
    if (chars.empty())
    {
        return 0;
    }
    return count(chars, ch, chars.length() - 1);
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
            throw std::runtime_error("Failed to read characters line.");
        }

        std::cout << "Enter a single character: ";
        char ch = '\0';
        if (!(std::cin >> ch))
        {
            throw std::runtime_error("Failed to read character.");
        }

        std::cout << "The character '" << ch << "' occurs " 
                  << count(line, ch) << " times.\n";
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