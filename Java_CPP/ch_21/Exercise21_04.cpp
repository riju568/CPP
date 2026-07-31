#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cctype>
#include <exception>

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter the name of a text file to read: ";
        std::string fileName;
        if (!(std::cin >> fileName)) {
            throw std::runtime_error("Invalid non-string file name input.");
        }

        std::ifstream file(fileName);
        if (!file.is_open()) {
            throw std::runtime_error("File " + fileName + " does not exist or could not be opened.");
        }

        const std::unordered_set<char> vowels = {
            'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'
        };
        int numVowels = 0;
        int numConsonants = 0;
        char ch = '\0';
        while (file.get(ch)) {
            if (std::isalpha(static_cast<unsigned char>(ch))) {
                if (vowels.count(ch) > 0) {
                    numVowels++;
                } else {
                    numConsonants++;
                }
            }
        }
        std::cout << "Number of vowels = " << numVowels << '\n';
        std::cout << "Number of consonants = " << numConsonants << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }
    return 0;
}