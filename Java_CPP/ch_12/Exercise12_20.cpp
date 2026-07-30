#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string_view>
#include <filesystem>
#include <exception>
#include <cstdlib>

namespace fs = std::filesystem;

std::string_view trim_left(std::string_view sv)
{
    size_t start = sv.find_first_not_of(" \t\r\n");
    return (start == std::string_view::npos) ? "" : sv.substr(start);
}

bool is_package_declaration(std::string_view line)
{
    std::string_view trimmed = trim_left(line);
    if (trimmed.rfind("package ", 0) == 0) 
    {
        size_t semicolon_pos = trimmed.find(';');
        if (semicolon_pos != std::string_view::npos)
        {
            return true;
        }
    }
    return false;
}
void remove_package_from_file(const fs::path& file_path)
{
    std::vector<std::string> lines;
    bool modified = false;
    {
        std::ifstream in(file_path, std::ios::in);
        if (!in.is_open())
        {
            std::cerr << "Warning: Could not open file '" << file_path.string() << "' for reading.\n";
            return;
        }

        std::string line;
        while (std::getline(in, line))
        {
            if (is_package_declaration(line))
            {
                std::cout << "  [Removed] " << line << " from " << file_path.filename().string() << '\n';
                modified = true;
                continue; // Skip writing this line
            }
            lines.push_back(line);
        }
    } 
    if (modified)
    {
        std::ofstream out(file_path, std::ios::out | std::ios::trunc);
        if (!out.is_open())
        {
            std::cerr << "Error: Could not open file '" << file_path.string() << "' for writing.\n";
            return;
        }

        for (const auto& l : lines)
        {
            out << l << '\n';
        }
    } 
}

int main(int argc, char* argv[])
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        if (argc < 2)
        {
            std::cout << "Usage: " << argv[0] << " <srcRootDirectory>\n";
            return EXIT_SUCCESS;
        }
        const fs::path root_path = argv[1];

        if (!fs::exists(root_path))
        {
            std::cout << "Error: The specified root directory '" << root_path.string() 
                      << "' does not exist.\n";
            return EXIT_SUCCESS;
        }

        if (!fs::is_directory(root_path))
        {
            std::cout << "Error: Provided path is not a directory.\n";
            return EXIT_FAILURE;
        }

        std::cout << "Path resolved: " << fs::absolute(root_path).string() << '\n';
        for (const auto& entry : fs::directory_iterator(root_path))
        {
            if (entry.is_directory())
            {
                std::string folder_name = entry.path().filename().string();
                if (folder_name.rfind("chapter", 0) == 0)
                {
                    std::cout << "Processing package directory: " << folder_name << '\n';
                    for (const auto& file_entry : fs::directory_iterator(entry.path()))
                    {
                        if (file_entry.is_regular_file() && file_entry.path().extension() == ".java")
                        {
                            remove_package_from_file(file_entry.path());
                        }
                    }
                }
            }
        }

        std::cout << "Package statement removal completed successfully.\n";
        return EXIT_SUCCESS;
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << "Filesystem error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}