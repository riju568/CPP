#include <iostream>
#include <array>
#include <cctype>
#include <random>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <memory>
#include <string>

/**
 * Exercise 10.24 (Implement the Character class)
 * Custom wrapper class for char values with static utility operations.
 */
class MyCharacter
{
private:
    char value;
    static constexpr std::size_t CACHE_SIZE = 128;

public:
    static constexpr char MIN_VALUE = '\0';
    static constexpr char MAX_VALUE = '\x7F'; 
    MyCharacter() noexcept : value(MIN_VALUE) {}
    explicit MyCharacter(char value) noexcept : value(value) {}
    [[nodiscard]] char char_value() const noexcept { return value;  }

    [[nodiscard]] int compare_to(const MyCharacter &other) const noexcept  { return static_cast<int>(value) - static_cast<int>(other.value);  }
    [[nodiscard]] bool equals(const MyCharacter &other) const noexcept  {   return value == other.value;  }
    [[nodiscard]] std::string to_string() const  { return std::string(1, value); }
    static MyCharacter value_of(char c) noexcept  {  return MyCharacter(c); }
    static MyCharacter value_of(int i) 
    { 
        if (i < 0 || i > 255) 
        {
            throw std::out_of_range("Integer value out of character range (0-255).");
        }
        return MyCharacter(static_cast<char>(i));
    }
    static bool is_digit(char c) noexcept  { return std::isdigit(static_cast<unsigned char>(c)) != 0; }
    static bool is_letter(char c) noexcept { return std::isalpha(static_cast<unsigned char>(c)) != 0; }
    static bool is_lower_case(char c) noexcept  {  return std::islower(static_cast<unsigned char>(c)) != 0;  }
    static bool is_upper_case(char c) noexcept  {  return std::isupper(static_cast<unsigned char>(c)) != 0;  }
    static bool is_letter_or_digit(char c) noexcept {  return std::isalnum(static_cast<unsigned char>(c)) != 0; }
    static char to_lower_case(char c) noexcept  { return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));  }
    static char to_upper_case(char c) noexcept  { return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));  }
    bool operator==(const MyCharacter &other) const noexcept { return equals(other); }
    bool operator!=(const MyCharacter &other) const noexcept { return !equals(other); }
    bool operator<(const MyCharacter &other) const noexcept { return compare_to(other) < 0; }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::array<MyCharacter, 10> my_characters{};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(33, 126); // Printable ASCII range

        for (auto &obj : my_characters)
        {
            obj = MyCharacter::value_of(dist(gen));
        }

        std::cout << std::boolalpha;
        std::cout << "--- Testing MyCharacter Class ---\n\n";
        std::cout << "myCharacters[0] char value: " << MyCharacter::value_of(my_characters[0].char_value()).char_value() << '\n';
        std::cout << "myCharacters[4] char value: " << MyCharacter::value_of(my_characters[4].char_value()).char_value() << '\n';
        std::cout << "myCharacters[1] ('" << my_characters[1].char_value() << "') compareTo myCharacters[7] ('" << my_characters[7].char_value() << "'): " << my_characters[1].compare_to(my_characters[7]) << '\n';
        std::cout << "myCharacters[5] equals myCharacters[7]: " << my_characters[5].equals(my_characters[7]) << '\n';
        std::cout << "myCharacters[6] ('" << my_characters[6].char_value() << "') isDigit: " << MyCharacter::is_digit(my_characters[6].char_value()) << '\n';
        std::cout << "myCharacters[5] ('" << my_characters[5].char_value()   << "') isLetter: " << MyCharacter::is_letter(my_characters[5].char_value()) << '\n';
        std::cout << "myCharacters[9] ('" << my_characters[9].char_value() << "') isLowerCase: " << MyCharacter::is_lower_case(my_characters[9].char_value()) << '\n';
        std::cout << "myCharacters[3] ('" << my_characters[3].char_value() << "') isUpperCase: " << MyCharacter::is_upper_case(my_characters[3].char_value()) << '\n';

        try 
        {
            std::cout << "\nTesting out of range conversion:\n";
            MyCharacter invalid = MyCharacter::value_of(500); 
        } 
        catch (const std::out_of_range &e) 
        {
            std::cout << "Caught expected error: " << e.what() << '\n';
        }

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