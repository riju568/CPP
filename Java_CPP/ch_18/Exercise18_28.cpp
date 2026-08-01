#include <iostream>
#include <string>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;
std::uintmax_t getSize(const fs::path& filePath)
{
    if (!fs::exists(filePath))
    {
        return 0;
    }

    if (fs::is_regular_file(filePath))
    {
        return fs::file_size(filePath);
    }

    std::uintmax_t totalBytes = 0;

    if (fs::is_directory(filePath))
    {
        for (const auto& entry : fs::recursive_directory_iterator(filePath, fs::directory_options::skip_permission_denied))
        {
            if (entry.is_regular_file())
            {
                totalBytes += entry.file_size();
            }
        }
    }

    return totalBytes;
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a directory or a file: ";
        std::string inputPath;
        if (!std::getline(std::cin, inputPath))
        {
            throw std::runtime_error("Failed to read input path.");
        }

        fs::path path(inputPath);
        std::cout << "The file/directory: " << path.filename().string() 
                  << " contains " << getSize(path) << " bytes\n";
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