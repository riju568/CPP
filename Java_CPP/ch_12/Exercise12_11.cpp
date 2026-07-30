#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <filesystem>
#include <exception>
#include <cstdlib>

namespace fs = std::filesystem;



std::string remove_all_occurrences(std::string_view source, std::string_view target)
{
    if (target.empty() || source.empty())
    {
        return std::string(source);
    }
    std::string result;
    result.reserve(source.size()); 
    size_t start = 0;
    size_t pos = 0;
    while ((pos = source.find(target, start)) != std::string::npos)
    {
        result.append(source, start, pos - start);
        start = pos + target.length();
    }
    result.append(source, start);

    return result;
}

int main(int argc, char* argv[])
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        if (argc < 3)
        {
            std::cout << "Usage: " << argv[0] << " <string_to_remove> <filename>\n";
            return EXIT_SUCCESS;
        }
        const std::string_view to_remove = argv[1];
        const fs::path source_path = argv[2];
        if (!fs::exists(source_path))
        {
            std::cout << "The file " << source_path.filename().string() << " does not exist.\n";
            return EXIT_SUCCESS;
        }

        if (!fs::is_regular_file(source_path))
        {
            std::cout << "Error: Provided path is not a standard file.\n";
            return EXIT_FAILURE;
        }
        std::string file_content;
        {
            std::ifstream in(source_path, std::ios::in | std::ios::binary);
            if (!in.is_open())
            {
                std::cerr << "Error: Unable to open file '" << source_path.string() << "' for reading.\n";
                return EXIT_FAILURE;
            }
            file_content.assign((std::istreambuf_iterator<char>(in)),
                                std::istreambuf_iterator<char>());
        }
        std::string modified_content = remove_all_occurrences(file_content, to_remove);
        fs::path target_path = source_path.parent_path() / (std::string(to_remove) + "_Revised.txt");

        {
            std::ofstream out(target_path, std::ios::out | std::ios::binary);
            if (!out.is_open())
            {
                std::cerr << "Error: Unable to open output file '" << target_path.string() << "' for writing.\n";
                return EXIT_FAILURE;
            }

            out.write(modified_content.data(), static_cast<std::streamsize>(modified_content.size()));
        } 
        std::cout << "Your edited file is complete: " << target_path.filename().string() << '\n';
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