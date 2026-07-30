#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <exception>
#include <cstdlib>
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        if (argc < 2)
        {
            std::cout << "Usage: " << argv[0] << " <filename>\n";
            return EXIT_SUCCESS;
        }
        const fs::path source_path = argv[1];
        if (!fs::exists(source_path))
        {
            std::cout << "Please check your file name and try again: '" 
                      << source_path.string() << "' does not exist.\n";
            return EXIT_SUCCESS;
        }

        if (!fs::is_regular_file(source_path))
        {
            std::cout << "Error: Provided path is not a standard file.\n";
            return EXIT_FAILURE;
        }
        std::ifstream in(source_path, std::ios::in | std::ios::binary);
        if (!in.is_open())
        {
            std::cerr << "Error: Unable to open file '" << source_path.string() << "' for reading.\n";
            return EXIT_FAILURE;
        }

        std::size_t num_lines = 0;
        std::size_t num_words = 0;
        std::string line;
        while (std::getline(in, line))
        {
            num_lines++;
            std::istringstream line_stream(line);
            std::string word;
            while (line_stream >> word)
            {
                num_words++;
            }
        } 
        const std::size_t num_chars = fs::file_size(source_path);
        std::cout << "The file " << source_path.filename().string() << " has:\n";
        std::cout << num_chars << " Characters\n";
        std::cout << num_words << " words\n";
        std::cout << num_lines << " lines\n";
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