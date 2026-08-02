#include <iostream>
#include <exception>
#include <memory>

class GridDisplay {
public:
    void renderGrid() {
        std::cout << "Initializing 3x3 Grid Rendering Context...\n";
        std::cout << "Vertical lines set to RED, Horizontal lines set to BLUE.\n";
    }
};

int main() {
    try {
        auto grid = std::make_unique<GridDisplay>();
        grid->renderGrid();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception caught.\n";
        return 2;
    }
    return 0;
}