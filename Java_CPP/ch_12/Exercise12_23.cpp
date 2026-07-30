#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <cstdlib>

std::string read_file_content(const std::string &filepath)
{
    std::ifstream file(filepath, std::ios::in | std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filepath);
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        const std::string filepath = "scores.txt";
        std::cout << "Reading scores from " << filepath << "...\n";
        std::string content = read_file_content(filepath);
        std::istringstream stream(content);
        std::string token;
        double total = 0.0;
        std::size_t count = 0;
        while (stream >> token)
        {
            try
            {
                std::size_t processed_chars = 0;
                double score = std::stod(token, &processed_chars);
                if (processed_chars == token.length())
                {
                    total += score;
                    count++;
                }
            }
            catch (const std::invalid_argument &) {  }
            catch (const std::out_of_range &) {  }
        }
        if (count > 0)
        {
            double average = total / static_cast<double>(count);
            std::cout << "The total is " << total << '\n';
            std::cout << "The average score was " << std::fixed << std::setprecision(2) << average << '\n';
        }
        else
        {
            std::cout << "No valid numeric scores were found in the file.\n";
        }
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
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