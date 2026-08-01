#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;
std::size_t wordSearchInFile(const fs::path& filePath, std::string_view targetWord)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        return 0;
    }

    std::size_t count = 0;
    std::string line;

    while (std::getline(file, line))
    {
        if (line.find(targetWord) != std::string::npos)
        {
            count++;
        }
    }

    return count;
}

std::size_t wordSearchDirectory(const fs::path& dirPath, std::string_view targetWord)
{
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath))
    {
        return 0;
    }

    std::size_t occurrences = 0;

    for (const auto& entry : fs::recursive_directory_iterator(dirPath, fs::directory_options::skip_permission_denied))
    {
        if (entry.is_regular_file())
        {
            occurrences += wordSearchInFile(entry.path(), targetWord);
        }
    }

    return occurrences;
}

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        if (argc < 3)
        {
            std::cerr << "Usage: " << argv[0] << " <dirName> <word>\n";
            return 1;
        }

        fs::path dir(argv[1]);
        std::string word = argv[2];

        if (!fs::is_directory(dir))
        {
            std::cout << "Please specify a valid directory for 'dirName'.\n";
            return 3;
        }

        std::size_t totalOccurrences = wordSearchDirectory(dir, word);

        std::cout << "The word: \"" << word << "\" occurs " 
                  << totalOccurrences << " times in: " << dir.filename().string() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}