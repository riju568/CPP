#include <iostream>
#include <string>
#include <string_view>
#include <exception>


int count(std::string_view str, char a) {
    if (!str.empty()) {
        int match = (str.back() == a) ? 1 : 0;
        return match + count(str.substr(0, str.size() - 1), a);
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter a String and a character to count its occurrences: ";
        std::string str;
        char ch = '\0';

        if (!(std::cin >> str >> ch)) {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        int occurrences = count(str, ch);
        std::cout << "Character " << ch << " occurs " << occurrences << " times in " << str << '\n';
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