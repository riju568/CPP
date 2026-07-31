#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <exception>

struct WordOccurrence {
    std::string word;
    int count;
    bool operator<(const WordOccurrence& other) const {
        return count < other.count;
    }
};

class KeywordCounter {
private:
    const std::unordered_set<std::string> keywords = {
        "abstract", "assert", "boolean", "break", "byte", "case", "catch", "char",
        "class", "const", "continue", "default", "do", "double", "else", "enum",
        "extends", "for", "final", "finally", "float", "goto", "if", "implements",
        "import", "instanceof", "int", "interface", "long", "native", "new",
        "package", "private", "protected", "public", "return", "short", "static",
        "strictfp", "super", "switch", "synchronized", "this", "throw", "throws",
        "transient", "try", "void", "volatile", "while", "true", "false", "null"
    };

public:
    void processFile(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open source file: " + filepath);
        }
        std::unordered_map<std::string, int> keywordMap;
        std::string line;
        bool inBlockComment = false;
        while (std::getline(file, line)) {
            std::string word;
            bool inString = false;
            bool inLineComment = false;
            for (size_t i = 0; i < line.length(); ++i) {
                if (inBlockComment) {
                    if (i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
                        inBlockComment = false;
                        ++i; // Skip '/'
                    }
                    continue;
                }
                if (!inString && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                    inLineComment = true;
                    break; // Skip rest of the line
                }
                if (!inString && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                    inBlockComment = true;
                    ++i; // Skip '*'
                    continue;
                }
                if (line[i] == '"') {
                    inString = !inString;
                    continue;
                }

                if (inString || inLineComment) {
                    continue;
                }
                if (std::isalnum(static_cast<unsigned char>(line[i])) || line[i] == '_') {
                    word += line[i];
                } else {
                    if (!word.empty()) {
                        if (keywords.count(word) > 0) {
                            keywordMap[word]++;
                        }
                        word.clear();
                    }
                }
            }
            if (!word.empty() && !inString && !inBlockComment && !inLineComment) {
                if (keywords.count(word) > 0) {
                    keywordMap[word]++;
                }
            }
        }
        if (keywordMap.empty()) {
            std::cout << "No keywords found in file.\n";
            return;
        }
        std::vector<WordOccurrence> wordOccurrences;
        wordOccurrences.reserve(keywordMap.size());
        for (const auto& pair : keywordMap) {
            wordOccurrences.push_back({pair.first, pair.second});
        }
        std::sort(wordOccurrences.begin(), wordOccurrences.end());
        for (const auto& item : wordOccurrences) {
            std::cout << "WordOccurrence{word='" << item.word << "', count=" << item.count << "}\n";
        }
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        if (argc < 2) {
            std::cout << "Usage: " << argv[0] << " <FileToTest.java>\n";
            return 1;
        }
        std::string inputFile = argv[1];
        std::cout << "Reading file: " << inputFile << "\n";
        KeywordCounter counter;
        counter.processFile(inputFile);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown fatal exception occurred.\n";
        return 2;
    }

    return 0;
}