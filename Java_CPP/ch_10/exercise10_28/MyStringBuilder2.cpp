#include <iostream>
#include <memory>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Exercise 10.28 (Implement the StringBuilder class)
 * Custom MyStringBuilder2 class translating Java implementation logic into Modern C++.
 */
class MyStringBuilder2
{
private:
    std::unique_ptr<char[]> values;
    std::size_t len;

public:
    MyStringBuilder2() : len(0), values(nullptr) {}

    MyStringBuilder2(const char *chars, std::size_t size)
        : len(size), values(size > 0 ? std::make_unique<char[]>(size) : nullptr)
    {
        if (size > 0 && chars != nullptr)
        {
            std::memcpy(values.get(), chars, size);
        }
    }

    explicit MyStringBuilder2(const std::string &s)
        : len(s.length()), values(s.length() > 0 ? std::make_unique<char[]>(s.length()) : nullptr)
    {
        if (len > 0)
        {
            std::memcpy(values.get(), s.data(), len);
        }
    }

    MyStringBuilder2(const MyStringBuilder2 &other)
        : len(other.len), values(other.len > 0 ? std::make_unique<char[]>(other.len) : nullptr)
    {
        if (len > 0)
        {
            std::memcpy(values.get(), other.values.get(), len);
        }
    }

    MyStringBuilder2(MyStringBuilder2 &&other) noexcept = default;

    MyStringBuilder2 &operator=(const MyStringBuilder2 &other)
    {
        if (this != &other)
        {
            len = other.len;
            values = len > 0 ? std::make_unique<char[]>(len) : nullptr;
            if (len > 0)
            {
                std::memcpy(values.get(), other.values.get(), len);
            }
        }
        return *this;
    }

    MyStringBuilder2 &operator=(MyStringBuilder2 &&other) noexcept = default;

    ~MyStringBuilder2() = default;

    MyStringBuilder2 &insert(int offset, const MyStringBuilder2 &s)
    {
        if (offset < 0 || static_cast<std::size_t>(offset) > len)
        {
            throw std::out_of_range("Offset out of bounds for insertion.");
        }

        std::size_t off = static_cast<std::size_t>(offset);
        std::size_t newLength = len + s.len;
        auto nuVals = std::make_unique<char[]>(newLength);
        if (off > 0)
        {
            std::memcpy(nuVals.get(), values.get(), off);
        }
        if (s.len > 0)
        {
            std::memcpy(nuVals.get() + off, s.values.get(), s.len);
        }
        if (len - off > 0)
        {
            std::memcpy(nuVals.get() + off + s.len, values.get() + off, len - off);
        }

        values = std::move(nuVals);
        len = newLength;
        return *this;
    }

    MyStringBuilder2 &reverse()
    {
        if (len > 1)
        {
            std::reverse(values.get(), values.get() + len);
        }
        return *this;
    }

    [[nodiscard]] MyStringBuilder2 substring(int begin) const
    {
        if (begin < 0 || static_cast<std::size_t>(begin) > len)
        {
            throw std::out_of_range("Begin index out of bounds.");
        }

        std::size_t beg = static_cast<std::size_t>(begin);
        std::size_t newLen = len - beg;

        return MyStringBuilder2(values.get() + beg, newLen);
    }

    MyStringBuilder2 &toUpperCase()
    {
        for (std::size_t i = 0; i < len; ++i)
        {
            values[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(values[i])));
        }
        return *this;
    }

    [[nodiscard]] std::string toString() const
    {
        return len > 0 ? std::string(values.get(), len) : "";
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        MyStringBuilder2 myStringBuilder2("SuperCalifradolistic");
        std::cout << "Start MyStringBuilder2 values: " << myStringBuilder2.toString() << '\n';
        std::cout << "ToUpperCase: " << myStringBuilder2.toUpperCase().toString() << '\n';
        std::cout << "Insert: ";
        myStringBuilder2.insert(3, MyStringBuilder2("TESTinsertTEST"));
        std::cout << myStringBuilder2.toString() << '\n';
        std::cout << "Reverse: ";
        std::cout << myStringBuilder2.reverse().toString() << '\n';
        std::cout << "subString: " << myStringBuilder2.substring(5).toString() << '\n';

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