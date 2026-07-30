#include <iostream>
#include <memory>
#include <cstring>
#include <cctype>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Exercise 10.27 (Implement the StringBuilder class)
 * Direct C++ translation of Java's MyStringBuilder1 class using smart pointers.
 */
class MyStringBuilder1
{
private:
    std::unique_ptr<char[]> values;
    std::size_t len;

public:
    explicit MyStringBuilder1(const std::string &s) 
        : len(s.length()), values(std::make_unique<char[]>(s.length()))
    {
        std::memcpy(values.get(), s.data(), len);
    }

    // Copy Constructor (Deep copy for RAII memory safety)
    MyStringBuilder1(const MyStringBuilder1 &other) 
        : len(other.len), values(std::make_unique<char[]>(other.len))
    {
        std::memcpy(values.get(), other.values.get(), len);
    }
    MyStringBuilder1(MyStringBuilder1 &&other) noexcept = default;
    MyStringBuilder1 &operator=(const MyStringBuilder1 &other)
    {
        if (this != &other)
        {
            len = other.len;
            values = std::make_unique<char[]>(len);
            std::memcpy(values.get(), other.values.get(), len);
        }
        return *this;
    }

    // Move Assignment Operator
    MyStringBuilder1 &operator=(MyStringBuilder1 &&other) noexcept = default;
    ~MyStringBuilder1() = default;
    MyStringBuilder1 &append(const MyStringBuilder1 &s)
    {
        std::size_t oldLength = this->len;
        std::size_t newLength = oldLength + s.len;
        auto nuValues = std::make_unique<char[]>(newLength);
        std::memcpy(nuValues.get(), this->values.get(), oldLength);
        std::memcpy(nuValues.get() + oldLength, s.values.get(), s.len);
        this->values = std::move(nuValues);
        this->len = newLength;
        return *this;
    }
    MyStringBuilder1 &append(int i)
    {
        std::size_t oldLength = this->len;
        std::string temp = std::to_string(i);
        std::size_t newLength = oldLength + temp.length();
        auto nuVals = std::make_unique<char[]>(newLength);
        std::memcpy(nuVals.get(), this->values.get(), oldLength);
        std::memcpy(nuVals.get() + oldLength, temp.data(), temp.length());
        this->values = std::move(nuVals);
        this->len = newLength;
        return *this;
    }
    [[nodiscard]] int length() const noexcept
    {
        return static_cast<int>(len);
    }
    [[nodiscard]] char charAt(int index) const
    {
        if (index < 0 || static_cast<std::size_t>(index) >= len)
        {
            throw std::out_of_range("Index out of bounds in MyStringBuilder1.");
        }
        return values[index];
    }
    [[nodiscard]] MyStringBuilder1 toLowerCase() const
    {
        std::string lowerStr;
        lowerStr.reserve(len);
        for (std::size_t i = 0; i < len; ++i)
        {
            lowerStr.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(values[i]))));
        }
        return MyStringBuilder1(lowerStr);
    }
    MyStringBuilder1 &substring(int begin, int end)
    {
        if (begin < 0 || end < begin || static_cast<std::size_t>(end) > len)
        {
            throw std::out_of_range("Invalid substring bounds.");
        }

        std::size_t newLen = static_cast<std::size_t>(end - begin);
        auto nuVals = std::make_unique<char[]>(newLen);

        std::memcpy(nuVals.get(), this->values.get() + begin, newLen);

        this->values = std::move(nuVals);
        this->len = newLen;
        return *this;
    }
    [[nodiscard]] std::string toString() const
    {
        return std::string(values.get(), len);
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        MyStringBuilder1 stringBuilder1("SOMESTRINGTESTHERE");
        std::cout << stringBuilder1.toLowerCase().toString() << '\n';
        std::cout << stringBuilder1.length() << '\n';
        MyStringBuilder1 &stringBuilder3 = stringBuilder1.append(12);
        std::cout << stringBuilder1.toString() << '\n';
        std::cout << stringBuilder3.toString() << '\n';
        MyStringBuilder1 stringBuilder2("AddedSomeStringhere");
        stringBuilder1.append(stringBuilder2);
        std::cout << stringBuilder1.toString() << '\n';
        std::cout << stringBuilder1.substring(3, 11).toString() << '\n';
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