#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <exception>
#include <utility>

std::vector<std::string> getVertices();
std::vector<std::pair<int, int>> getEdges();
void writeGraphToFile(std::ostream& output, const std::vector<std::string>& vertices, const std::vector<std::pair<int, int>>& edges);

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::filesystem::path filePath = "Exercise28_02.txt";

        if (std::filesystem::exists(filePath)) {
            std::cout << "Deleting old: " << std::filesystem::absolute(filePath).string() << '\n';
            std::filesystem::remove(filePath);
        }
        std::ofstream output(filePath);
        if (!output.is_open()) {
            throw std::runtime_error("Failed to open file for writing: " + filePath.string());
        }
        std::cout << "Writing new: " << std::filesystem::absolute(filePath).string() << '\n';
        writeGraphToFile(output, getVertices(), getEdges());
        
        std::cout << "Done!\n";
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}

void writeGraphToFile(std::ostream& output, const std::vector<std::string>& vertices, const std::vector<std::pair<int, int>>& edges) {
    const size_t numberOfVertices = vertices.size();
    output << numberOfVertices << '\n';

    for (size_t startingVertex = 0; startingVertex < numberOfVertices; ++startingVertex) {
        output << startingVertex;
        
        for (const auto& [u, v] : edges) {
            if (static_cast<size_t>(u) == startingVertex) {
                output << " " << v;
            }
        }
        output << '\n';
    }
}

std::vector<std::string> getVertices() {
    return {
        "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas City",
        "Chicago", "Boston", "New York", "Atlanta", "Miami", "Dallas", "Houston"
    };
}

std::vector<std::pair<int, int>> getEdges() {
    return {
        {0, 1}, {0, 3}, {0, 5},
        {1, 0}, {1, 2}, {1, 3},
        {2, 1}, {2, 3}, {2, 4}, {2, 10},
        {3, 0}, {3, 1}, {3, 2}, {3, 4}, {3, 5},
        {4, 2}, {4, 3}, {4, 5}, {4, 7}, {4, 8}, {4, 10},
        {5, 0}, {5, 3}, {5, 4}, {5, 6}, {5, 7},
        {6, 5}, {6, 7},
        {7, 4}, {7, 5}, {7, 6}, {7, 8},
        {8, 4}, {8, 7}, {8, 9}, {8, 10}, {8, 11},
        {9, 8}, {9, 11},
        {10, 2}, {10, 4}, {10, 8}, {10, 11},
        {11, 8}, {11, 9}, {11, 10}
    };
}