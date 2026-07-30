#include <iostream>
#include <array>
#include <cctype>
#include <random>
#include <stdexcept>
#include <exception>
#include <cstdlib>



/**
 * *10.24 (Implement the Character class) The Character class is provided in the C++ library.
 * Provide your own implementation for the MyCharacter class and test its functionality.
 */

class MyCharacter
{
private:
    char value;

public:
    MyCharacter() : value('\0') {}
    MyCharacter(char value) : value(value) {}
    char char_value() const { return value; }
    int compare_to(const MyCharacter &c) const { return static_cast<int>(value) - static_cast<int>(c.value); }
    bool equals(const MyCharacter &c) const { return value == c.value; }
    static MyCharacter value_of(char c) { return MyCharacter(c); }
    static MyCharacter value_of(int i)  { return MyCharacter(static_cast<char>(i));}
    static bool is_digit(char c) { return std::isdigit(static_cast<unsigned char>(c)) != 0; }
    static bool is_letter(char c) { return std::isalpha(static_cast<unsigned char>(c)) != 0; }
    static bool is_lower_case(char c)  {  return std::islower(static_cast<unsigned char>(c)) != 0; }
    static bool is_upper_case(char c) { return std::isupper(static_cast<unsigned char>(c)) != 0; }
    static char to_lower_case(char c) { return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));  }
    static char to_upper_case(char c)  { return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));  }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::array<MyCharacter, 10> my_characters;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 123);
        for (int i = 0; i < 10; ++i)
        {
            my_characters[i] = MyCharacter::value_of(dist(gen));
        }
        std::cout << std::boolalpha;
        std::cout << "MyCharacter.valueOf(myCharacters[0].charValue()): "  << MyCharacter::value_of(my_characters[0].char_value()).char_value() << '\n';
        std::cout << "MyCharacter.valueOf(myCharacters[4].charValue()): " << MyCharacter::value_of(my_characters[4].char_value()).char_value() << '\n';
        std::cout << "myCharacters[1] = " << my_characters[1].char_value() << " , myCharacters[7] = " << my_characters[7].char_value() << " | myCharacters[1].compareTo(myCharacters[7]) : " << my_characters[1].compare_to(my_characters[7]) << '\n';
        std::cout << my_characters[5].equals(my_characters[7]) << '\n';
        std::cout << "myCharacters[6].charValue() = " << my_characters[6].char_value() << " | MyCharacter.isDigit(myCharacters[6].charValue()): ):  " << MyCharacter::is_digit(my_characters[6].char_value()) << '\n';
        std::cout << MyCharacter::is_letter(my_characters[5].char_value()) << '\n';
        std::cout << "myCharacters[9] = " << my_characters[9].char_value() << " | (MyCharacter.isLowerCase, (myCharacters[9].charValue()) :" << MyCharacter::is_lower_case(my_characters[9].char_value()) << '\n';
        std::cout << "myCharacters[3] = " << my_characters[3].char_value()  << " | MyCharacter.isUpperCase(myCharacters[3].charValue())): "<< MyCharacter::is_upper_case(my_characters[3].char_value()) << '\n';
        std::cout << "myCharacters[3] = " << my_characters[3].char_value() << ", myCharacters[4] = " << my_characters[4].char_value()  << " | myCharacters[3].compareTo(myCharacters[4])): " << my_characters[3].compare_to(my_characters[4]) << '\n';
        std::cout << "myCharacters[2] = " << my_characters[2].char_value() << " , myCharacters[8] = " << my_characters[8].char_value() << " | myCharacters[2].compareTo(myCharacters[8])): " << my_characters[2].compare_to(my_characters[8]) << '\n';
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