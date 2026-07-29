#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <initializer_list>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <cstdlib>


/**
 * *10.22 (Implement the String class) The String class is provided in the C++ library.
 * Provide your own implementation for the following methods (name the new class MyString1):
 * ■ MyString1(const std::vector<char>& chars)
 * ■ char char_at(int index)
 * ■ int length()
 * ■ MyString1 substring(int begin, int end)
 * ■ MyString1 to_lower_case()
 * ■ bool equals(const MyString1& s)
 * ■ static MyString1 value_of(int i)
 */

class MyString1
{
private:
    std::vector<char> chars;

public:
    MyString1(const std::vector<char> &chars) : chars(chars) {}
    MyString1(std::initializer_list<char> list) : chars(list) {}

    char char_at(int index) const
    {
        if (index < 0 || index >= static_cast<int>(chars.size()))
        {
            throw std::out_of_range("Error: Index out of bounds.");
        }
        return chars[index];
    }

    int length() const { return static_cast<int>(chars.size()); }

    MyString1 substring(int begin, int end) const
    {
        if (begin < 0 || end > static_cast<int>(chars.size()) || begin > end)
        {
            throw std::out_of_range("Error: Invalid substring range.");
        }
        return MyString1(std::vector<char>(chars.begin() + begin, chars.begin() + end));
    }

    MyString1 to_lower_case() const
    {
        std::vector<char> lower = chars;
        for (char &c : lower)
        {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
        return MyString1(lower);
    }

    bool equals(const MyString1 &s) const { return chars == s.chars; }

    static MyString1 value_of(int i)
    {
        std::string str = std::to_string(i);
        return MyString1(std::vector<char>(str.begin(), str.end()));
    }

    std::vector<char> get_chars() const { return chars; }

    std::string to_array_string() const
    {
        std::ostringstream oss;
        oss << '[';
        for (size_t idx = 0; idx < chars.size(); ++idx)
        {
            oss << chars[idx] << (idx + 1 < chars.size() ? ", " : "");
        }
        oss << ']';
        return oss.str();
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        MyString1 s1({'T', 'E', 'S', 'T', '1'});
        MyString1 s2({'T', 'E', 'S', 'T', '1'});
        MyString1 s3({'T', 'E', 'S', 'T', '2'});
        std::cout << std::boolalpha;
        std::cout << "s1.equals(s2): " << s1.equals(s2) << '\n';
        std::cout << "s1.equals(s3): " << s1.equals(s3) << '\n';
        std::cout << "s1.substring(1, 3).chars: " << s1.substring(1, 3).to_array_string() << '\n';
        std::cout << "s3.char_at(2): " << s3.char_at(2) << '\n';
        std::cout << "MyString1::value_of(7).chars: " << MyString1::value_of(7).to_array_string() << '\n';
        std::cout << "s2.to_lower_case().chars: " << s2.to_lower_case().to_array_string() << '\n';
        std::cout << "s1.length(): " << s1.length() << '\n';

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