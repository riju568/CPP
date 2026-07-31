#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <exception>

int countKeywords(const std::string& filepath) {
    const std::unordered_set<std::string> keywords = {
        "abstract", "assert", "boolean", "break", "byte", "case", "catch", "char", 
        "class", "const", "continue", "default", "do", "double", "else", "enum", 
        "extends", "for", "final", "finally", "float", "goto", "if", "implements", 
        "import", "instanceof", "int", "interface", "long", "native", "new", 
        "package", "private", "protected", "public", "return", "short", "static", 
        "strictfp", "super", "switch", "synchronized", "this", "throw", "throws", 
        "transient", "try", "void", "volatile", "while", "true", "false", "null"
    };

    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("File " + filepath + " does not exist or could not be found.");
    }

    int count = 0;
    std::string word;
    bool inComment = false;
    bool inString = false;

    while (file >> word) {
        if (word.find("//") != std::string::npos) {
            std::string lineRemainder;
            std::getline(file, lineRemainder);
            continue;
        }

        if (word.find("/*") != std::string::npos) {
            inComment = true;
            while (inComment && file >> word) {
                if (word.find("*/") != std::string::npos) {
                    inComment = false;
                }
            }
            continue;
        }

        if (word.find("\"") != std::string::npos) {
            inString = true;
            while (inString && file >> word) {
                if (word.find("\"") != std::string::npos) {
                    inString = false;
                }
            }
            continue;
        }

        if (keywords.count(word) > 0) {
            count++;
        }
    }

    return count;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        if (argc < 2) {
            std::cout << "Please add the source file path to read from to the command line argument.\n";
            return 1;
        }

        std::string filename = argv[1];
        int count = countKeywords(filename);
        std::cout << "The number of keywords in " << filename << " is " << count << '\n';

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}