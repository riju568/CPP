#include <iostream>
#include <string>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;

std::uintmax_t getFileCount(const fs::path& dirPath)
{
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath))
    {
        return 0;
    }

    std::uintmax_t totalFiles = 0;

    for (const auto& entry : fs::directory_iterator(dirPath, fs::directory_options::skip_permission_denied))
    {
        if (entry.is_regular_file())
        {
            totalFiles++;
        }
    }

    return totalFiles;
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a directory: ";
        std::string inputPath;
        if (!std::getline(std::cin, inputPath))
        {
            throw std::runtime_error("Failed to read directory path.");
        }

        fs::path path(inputPath);
        if (fs::is_directory(path))
        {
            std::cout << "The directory: " << path.filename().string() 
                      << " contains " << getFileCount(path) << " files.\n";
        }
        else
        {
            std::cout << "Please ensure you are entering a valid directory.\n";
        }
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