#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <exception>
#include <stdexcept>

class WordSorter {
public:
    static void process_file(const std::string& file_path) {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + file_path);
        }

        std::vector<std::string> words;
        std::string word;

        while (file >> word) {
            if (!word.empty() && std::isalpha(static_cast<unsigned char>(word[0]))) {
                words.push_back(word);
            }
        }

        std::sort(words.begin(), words.end());

        std::cout << "Words in ascending alphabetical order (" << words.size() << " total):\n[ ";
        for (const auto& w : words) {
            std::cout << w << " ";
        }
        std::cout << "]\n";
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::string file_name;
        if (argc > 1) {
            file_name = argv[1];
        } else {
            std::cout << "Enter text file path: ";
            if (!(std::cin >> file_name)) {
                std::cerr << "Error: Invalid file path input.\n";
                return 3;
            }
        }

        WordSorter::process_file(file_name);
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}