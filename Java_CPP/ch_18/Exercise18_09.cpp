#include <iostream>
#include <string>
#include <string_view>
#include <exception>


void reverseDisplay(std::string_view value) {
    if (!value.empty()) {
        std::cout << value.back();
        reverseDisplay(value.substr(0, value.size() - 1));
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter a string to reverse: ";
        std::string s;

        if (!std::getline(std::cin, s)) {
            std::cerr << "Error: Invalid input stream.\n";
            return 3;
        }

        reverseDisplay(s);
        std::cout << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}