#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <limits> // Included for numeric_limits

class MyInteger
{
private:
    int value{0};

public:
    explicit MyInteger(int newValue) : value(newValue) {}
    [[nodiscard]] int getValue() const { return value; }
    [[nodiscard]] bool isEven() const { return isEven(value); }
    [[nodiscard]] bool isOdd() const { return isOdd(value); }
    [[nodiscard]] bool isPrime() const { return isPrime(value); }
    static bool isEven(int a) { return a % 2 == 0; }
    static bool isOdd(int a) { return a % 2 != 0; }
    static bool isPrime(int a)
    {
        if (a <= 1)
            return false;
        if (a == 2)
            return true;
        if (a % 2 == 0)
            return false;

        // Use integer arithmetic instead of calling std::sqrt inside the loop condition
        for (int i = 3; i * i <= a; i += 2)
        {
            if (a % i == 0)
                return false;
        }
        return true;
    }
    static bool isEven(const MyInteger &obj) { return obj.isEven(); }
    static bool isOdd(const MyInteger &obj) { return obj.isOdd(); }
    static bool isPrime(const MyInteger &obj) { return obj.isPrime(); }
    static bool isEven(const std::shared_ptr<MyInteger> &obj) { return obj && obj->isEven(); }
    static bool isOdd(const std::shared_ptr<MyInteger> &obj) { return obj && obj->isOdd(); }
    static bool isPrime(const std::shared_ptr<MyInteger> &obj) { return obj && obj->isPrime(); }
    [[nodiscard]] bool equals(int a) const { return value == a; }
    [[nodiscard]] bool equals(const MyInteger &a) const { return value == a.getValue(); }
    [[nodiscard]] bool equals(const std::shared_ptr<MyInteger> &a) const
    {
        return a && value == a->getValue();
    }

    static int parseInt(const std::vector<char> &arr)
    {
        if (arr.empty())
        {
            throw std::invalid_argument("Cannot parse empty character array.");
        }

        int result = 0;
        for (char ch : arr)
        {
            if (!std::isdigit(static_cast<unsigned char>(ch)))
            {
                throw std::invalid_argument("Character array contains non-digit elements.");
            }
            result = result * 10 + (ch - '0');
        }
        return result;
    }

    static int parseInt(const std::string &a)
    {
        if (a.empty())
        {
            throw std::invalid_argument("Cannot parse empty string.");
        }

        std::size_t processed_chars = 0;
        int result = 0;

        try
        {
            result = std::stoi(a, &processed_chars);
        }
        catch (const std::exception &)
        {
            throw std::invalid_argument("String cannot be converted to a valid integer.");
        }

        if (processed_chars != a.length())
        {
            throw std::invalid_argument("String contains unparseable trailing characters.");
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
        std::string str = testObj->isEven() ? "Even" : "Odd";
        if (testObj->isPrime())
            str += " and Prime";

        std::cout << "The first MyInteger test object " << testObj->getValue() << " is found to be " << str << "\n";

        std::string str2 = testObj2->isEven() ? "Even" : "Odd";
        if (testObj2->isPrime())
            str2 += " and Prime";
        std::cout << "The second MyInteger test object " << testObj2->getValue() << " is found to be " << str2 << "\n";
        std::cout << "Please enter an integer number to compare with test object one:\n";
        int j = 0;
        if (!(std::cin >> j))
        { // Fixed missing opening brace here
            std::cout << "Invalid integer input! Defaulting comparison value to 0.\n";
            std::cin.clear();                                                   // Clear stream fail states
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Robustly flush line
            j = 0;
        }

        std::string str3 = testObj->equals(j) ? "equal" : "not equal";
        std::cout << "Integer " << j << " and test object one " << testObj->getValue() << " are found to be " << str3 << "\n";
        std::vector<char> testArray = {'1', '2', '3', '4', '5'};
        try
        {
            std::cout << "The test array of numeric characters 1 2 3 4 5 has an integer value of: " << MyInteger::parseInt(testArray) << "\n";
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
                std::cout << "The test string \"" << testString << "\" is now the integer number " << MyInteger::parseInt(testString) << "\n";
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Error: The provided string cannot be parsed into a valid integer (" << e.what() << ")\n";
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
        std::cerr << "An unknown fatal error occurred.\n";
        return EXIT_FAILURE;
    }
}