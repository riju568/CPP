#include <iostream>
#include <string>
#include <exception>

int count(const std::string& str, char ch, std::size_t high)
{
    if (str.empty())
    {
        return 0;
    }

    int match = (str[high] == ch) ? 1 : 0;
    
    if (high == 0)
    {
        return match;
    }

    return match + count(str, ch, high - 1);
}

int count(const std::string& str, char ch)
{
    if (str.empty())
    {
        return 0;
    }
    return count(str, ch, str.length() - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a string and a character: ";
        std::string str;
        char ch = '\0';

        if (!(std::cin >> str >> ch))
        {
            throw std::runtime_error("Invalid input stream state encountered.");
        }

        std::cout << "Character '" << ch << "' occurs " 
                  << count(str, ch) << " times in " << str << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred.\n";
        return 2;
    }

    return 0;
}