#include <iostream>
#include <stack>
#include <filesystem>
#include <string>
#include <exception>
#include <cstdint>

namespace fs = std::filesystem;


std::uintmax_t get_directory_size_stack(const fs::path& start_path) {
    std::uintmax_t total_size = 0;
    std::stack<fs::path> path_stack;
    path_stack.push(start_path);

    while (!path_stack.empty()) {
        fs::path current = path_stack.top();
        path_stack.pop();

        std::error_code ec;
        if (fs::is_regular_file(current, ec)) {
            total_size += fs::file_size(current, ec);
        } else if (fs::is_directory(current, ec)) {
            for (const auto& entry : fs::directory_iterator(current, fs::directory_options::skip_permission_denied, ec)) {
                path_stack.push(entry.path());
            }
        }
    }
    return total_size;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter a directory or a file: ";
        std::string input_path;
        if (!(std::cin >> input_path)) {
            std::cerr << "Error: Invalid path input.\n";
            return 3;
        }

        fs::path target(input_path);
        if (!fs::exists(target)) {
            std::cout << "Path does not exist.\n";
            return 0;
        }

        std::uintmax_t size = get_directory_size_stack(target);
        std::cout << size << " bytes\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}