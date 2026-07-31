#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <exception>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        if (argc < 2) {
            throw std::invalid_argument("Missing file path argument. Usage: " + std::string(argv[0]) + " <filename.txt>");
        }

        std::string filename = argv[1];
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        std::set<std::string> words;
        std::string word;

        while (file >> word) {
            words.insert(word);
        }

        std::cout << '[';
        bool first = true;
        for (const auto& w : words) {
            if (!first) std::cout << ", ";
            std::cout << w;
            first = false;
        }
        std::cout << "]\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}