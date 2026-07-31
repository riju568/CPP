#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <exception>

struct WordOccurrence {
    std::string word;
    int count;

    bool operator<(const WordOccurrence& other) const {
        return count < other.count;
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        const std::string text = "Good morning. Have a good class. Have a good visit. Have fun!";
        std::unordered_map<std::string, int> wordMap;

        std::string currentWord;
        for (char ch : text) {
            if (std::isalnum(static_cast<unsigned char>(ch))) {
                currentWord += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
            } else if (!currentWord.empty()) {
                wordMap[currentWord]++;
                currentWord.clear();
            }
        }
        if (!currentWord.empty()) {
            wordMap[currentWord]++;
        }

        std::vector<WordOccurrence> wordOccurrences;
        wordOccurrences.reserve(wordMap.size());
        for (const auto& pair : wordMap) {
            wordOccurrences.push_back({pair.first, pair.second});
        }

        std::sort(wordOccurrences.begin(), wordOccurrences.end());

        for (const auto& item : wordOccurrences) {
            std::cout << "WordOccurrence{word='" << item.word << "', count=" << item.count << "}\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown fatal error occurred.\n";
        return 2;
    }
    return 0;
}