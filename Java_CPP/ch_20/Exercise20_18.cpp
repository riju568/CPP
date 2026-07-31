#include <iostream>
#include <queue>
#include <filesystem>
#include <string>
#include <exception>
#include <cstdint>

namespace fs = std::filesystem;

std::uintmax_t get_directory_size_queue(const fs::path& start_path) {
    std::uintmax_t total_size = 0;
    std::queue<fs::path> path_queue;
    path_queue.push(start_path);

    while (!path_queue.empty()) {
        fs::path current = path_queue.front();
        path_queue.pop();

        std::error_code ec;
        if (fs::is_regular_file(current, ec)) {
            total_size += fs::file_size(current, ec);
        } else if (fs::is_directory(current, ec)) {
            for (const auto& entry : fs::directory_iterator(current, fs::directory_options::skip_permission_denied, ec)) {
                path_queue.push(entry.path());
            }
        }
    }
    return total_size;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        const fs::path test_directory = "ch_09";
        
        if (!fs::exists(test_directory)) {
            std::cout << "Directory '" << test_directory.string() << "' does not exist in the current path.\n";
            return 0;
        }

        std::uintmax_t size = get_directory_size_queue(test_directory);
        std::cout << "Size of test directory: " << test_directory.string() << " is " << size << " bytes\n";
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