#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <cstdlib>



class MyInteger
{
private:
    int value{0};

public:
    explicit MyInteger(int val) : value(val) {}

    [[nodiscard]] int getValue() const
    {
        return value;
    }
    [[nodiscard]] bool isEven() const { return isEven(value); }
    [[nodiscard]] bool isOdd() const { return isOdd(value); }
    [[nodiscard]] bool isPrime() const { return isPrime(value); }
    static bool isEven(int val) { return val % 2 == 0; }
    static bool isOdd(int val) { return val % 2 != 0; }
    static bool isPrime(int val)
    {
        if (val <= 1) return false;
        for (int i = 2; i <= std::sqrt(val); ++i)
        {
            if (val % i == 0) return false;
        }
        return true;
    }
    static bool isEven(const MyInteger &obj) { return obj.isEven(); }
    static bool isOdd(const MyInteger &obj) { return obj.isOdd(); }
    static bool isPrime(const MyInteger &obj) { return obj.isPrime(); }
    [[nodiscard]] bool equals(int val) const { return value == val; }
    [[nodiscard]] bool equals(const MyInteger &obj) const { return value == obj.getValue(); }
    static int parseInt(const std::vector<char> &chars)
    {
        if (chars.empty())
        {
            throw std::invalid_argument("Empty character array provided.");
        }

        int result = 0;
        for (char ch : chars)
        {
            if (!std::isdigit(static_cast<unsigned char>(ch)))
            {
                throw std::invalid_argument("Array contains non-numeric characters.");
            }
            result = result * 10 + (ch - '0');
        }
        return result;
    }
    static int parseInt(const std::string &str)
    {
        if (str.empty())
        {
            throw std::invalid_argument("Empty string provided.");
        }

        std::size_t processed_chars = 0;
        int result = 0;

        try
        {
            result = std::stoi(str, &processed_chars);
        }
        catch (const std::exception &)
        {
            throw std::invalid_argument("String cannot be parsed into a valid integer.");
        }
        if (processed_chars != str.length())
        {
            throw std::invalid_argument("String contains trailing invalid characters.");
        }

        return result;
    }
};
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        auto testObj = std::make_shared<MyInteger>(123);
        auto testObj2 = std::make_shared<MyInteger>(24);
        std::string str;
        if (testObj->isEven())
        {
            str += "Even";
        }
        else if (testObj->isOdd())
        {
            str += "Odd";
        }
        else if (testObj->isPrime())
        {
            str += "Prime";
        }
        std::cout << "The first MyInteger test object " << testObj->getValue()
                  << " is found to be " << str << "\n";
        std::string str2;
        if (testObj2->isEven())
        {
            str2 += "Even";
        }
        else if (testObj2->isOdd())
        {
            str2 += "Odd";
        }
        else if (testObj2->isPrime())
        {
            str2 += "Prime";
        }
        std::cout << "The second MyInteger test object " << testObj2->getValue() << " is found to be " << str2 << "\n";

        std::cout << "Please enter an integer number to compare with test object one:\n";
        int j = 0;
        if (!(std::cin >> j))
        {
            std::cout << "Invalid integer input! Defaulting comparison value to 0.\n";
            std::cin.clear(); 
            std::string dummy;
            std::cin >> dummy; 
            j = 0;
        }
        std::string str3 = testObj->equals(j) ? "equal" : "not equal";
        std::cout << "Integer " << j << " and test object one " << testObj->getValue() << " are found to be " << str3 << "\n";
        std::vector<char> testArray = {'1', '2', '3', '4', '5'};
        try
        {
            std::cout << "The test array of numeric characters 1 2 3 4 5 has an sum integer value of: " << MyInteger::parseInt(testArray) << "\n";
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Array Parse Error: " << e.what() << "\n";
        }
        std::cout << "Enter a string to convert to an Integer: \n";
        std::string testString;
        if (std::cin >> testString)
        {
            try
            {
                std::cout << "The test string " << testString << " is now the integer number " << MyInteger::parseInt(testString) << "\n";
            }
            catch (const std::invalid_argument &)
            {
                std::cout << "Error: The provided string cannot be parsed into a valid integer.\n";
            }
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fatal execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}