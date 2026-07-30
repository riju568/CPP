#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Exercise 10.27 (Implement the StringBuilder class)
 * Custom string builder implementation mirroring Java's MyStringBuilder1 specification.
 */
class MyStringBuilder1
{
private:
    std::string data;

public:
    MyStringBuilder1() noexcept : data("") {}
    MyStringBuilder1(const std::string &s) : data(s) {}
    [[nodiscard]] std::size_t length() const noexcept { return data.length(); }
    [[nodiscard]] char char_at(std::size_t index) const
    {
        if (index >= data.length())
        {
            throw std::out_of_range("Index out of bounds for MyStringBuilder1.");
        }
        return data[index];
    }
    MyStringBuilder1& append(const MyStringBuilder1 &s)
    {
        data += s.data;
        return *this;
    }
    MyStringBuilder1& append(int i) { data += std::to_string(i); return *this; }
    [[nodiscard]] MyStringBuilder1 to_lower_case() const
    {
        std::string lower_str = data;
        std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                       [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        return MyStringBuilder1(lower_str);
    }
    [[nodiscard]] MyStringBuilder1 substring(std::size_t begin, std::size_t end) const
    {
        if (begin > end || end > data.length())
        {
            throw std::out_of_range("Invalid substring bounds.");
        }
        return MyStringBuilder1(data.substr(begin, end - begin));
    }
    [[nodiscard]] std::string to_string() const { return data; }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        MyStringBuilder1 stringBuilder1("SOMESTRINGTESTHERE");
        std::cout << stringBuilder1.to_lower_case().to_string() << '\n';
        std::cout << stringBuilder1.length() << '\n';
        MyStringBuilder1 &stringBuilder3 = stringBuilder1.append(12);
        std::cout << stringBuilder1.to_string() << '\n';
        std::cout << stringBuilder3.to_string() << '\n';
        MyStringBuilder1 stringBuilder2("AddedSomeStringhere");
        stringBuilder1.append(stringBuilder2);
        std::cout << stringBuilder1.to_string() << '\n';
        std::cout << stringBuilder1.substring(3, 11).to_string() << '\n';
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}