#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *10.23 (Implement the String class) The String class is provided in the C++ library.
 * Provide your own implementation for the following methods
 * ■ MyString2(const std::string& s)
 * ■ int compare(const std::string& s)
 * ■ MyString2 substring(int begin)
 * ■ MyString2 to_upper_case()
 * ■ std::vector<char> to_chars()
 * ■ static MyString2 value_of(bool b)
 */

class MyString2
{
private:
    std::string str;

public:
    MyString2(const std::string &s) : str(s) {}

    int compare(const std::string &s) const
    {
        return str.compare(s);
    }

    MyString2 substring(int begin) const
    {
        if (begin < 0 || begin > static_cast<int>(str.length()))
        {
            throw std::out_of_range("Error: Substring index out of bounds.");
        }
        return MyString2(str.substr(begin));
    }

    MyString2 to_upper_case() const
    {
        std::string upper = str;
        for (char &c : upper)
        {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }
        return MyString2(upper);
    }

    std::vector<char> to_chars() const
    {
        return std::vector<char>(str.begin(), str.end());
    }

    static MyString2 value_of(bool b)
    {
        return MyString2(b ? "true" : "false");
    }

    std::string get_str() const
    {
        return str;
    }
};

static std::string vector_to_array_string(const std::vector<char> &vec)
{
    std::ostringstream oss;
    oss << '[';
    for (size_t i = 0; i < vec.size(); ++i)
    {
        oss << vec[i] << (i + 1 < vec.size() ? ", " : "");
    }
    oss << ']';
    return oss.str();
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        MyString2 my_string21("Supercalifrajaliscousexpialidocious");
        MyString2 my_string22("abcdefghijklmnopqrstuvwxyz");
        std::string s = "abcdefghijklmnopqrstuvwxyz";
        MyString2 my_string113("HelloWorldWorldHelloWorld");
        MyString2 my_string4("MILO");
        MyString2 my_string5("SimonAndGarfunkel");
        std::cout << vector_to_array_string(my_string4.to_upper_case().to_chars()) << '\n';
        std::cout << my_string22.compare(s) << '\n';
        std::cout << my_string21.compare("SomeRandomString") << '\n';
        std::cout << vector_to_array_string(my_string113.substring(3).to_chars()) << '\n';
        std::cout << vector_to_array_string(my_string5.to_chars()) << '\n';

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}