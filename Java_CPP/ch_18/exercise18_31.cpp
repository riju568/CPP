#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;

/**
 * Replaces all occurrences of oldWord with newWord inside a string.
 */
std::string replaceAll(std::string str, const std::string& oldWord, const std::string& newWord)
{
    if (oldWord.empty())
    {
        return str;
    }

    std::size_t startPos = 0;
    while ((startPos = str.find(oldWord, startPos)) != std::string::npos)
    {
        str.replace(startPos, oldWord.length(), newWord);
        startPos += newWord.length();
    }
    return str;
}

/**
 * Reads a single file, replaces all occurrences of oldWord with newWord,
 * and overwrites the original file.
 */
void runReplace(const fs::path& filePath, const std::string& oldWord, const std::string& newWord)
{
    if (!fs::is_regular_file(filePath))
    {
        return;
    }

    std::vector<std::string> lines;
    {
        std::ifstream inFile(filePath);
        if (!inFile.is_open())
        {
            std::cerr << "Warning: Could not open file for reading: " << filePath << '\n';
            return;
        }

        std::string line;
        while (std::getline(inFile, line))
        {
            lines.push_back(replaceAll(line, oldWord, newWord));
        }
    } 

    {
        std::ofstream outFile(filePath, std::ios::trunc);
        if (!outFile.is_open())
        {
            std::cerr << "Warning: Could not open file for writing: " << filePath << '\n';
            return;
        }

        for (const auto& line : lines)
        {
            outFile << line << '\n';
        }
    }
}


void replaceWords(const fs::path& dirPath, const std::string& oldWord, const std::string& newWord)
{
    for (const auto& entry : fs::recursive_directory_iterator(dirPath, fs::directory_options::skip_permission_denied))
    {
        if (entry.is_regular_file())
        {
            runReplace(entry.path(), oldWord, newWord);
        }
    }
}

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        if (argc < 4)
        {
            std::cerr << "Usage: " << argv[0] << " <dirName> <oldWord> <newWord>\n";
            return 3;
        }

        fs::path dirPath(argv[1]);
        std::string oldWord = argv[2];
        std::string newWord = argv[3];

        if (!fs::exists(dirPath) || !fs::is_directory(dirPath))
        {
            std::cout << "Please specify a valid directory for 'dirName'.\n";
            return 3;
        }

        replaceWords(dirPath, oldWord, newWord);

        std::cout << "The word: \"" << oldWord << "\" has been replaced with \"" 
                  << newWord << "\" for files in directory: " 
                  << dirPath.filename().string() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}