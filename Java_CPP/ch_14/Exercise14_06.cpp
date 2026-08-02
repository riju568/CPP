#include <QApplication>
#include <QGridLayout>
#include <QWidget>
#include <iostream>
#include <exception>
#include <memory>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        QApplication app(argc, argv);
        
        auto window = std::make_shared<QWidget>();
        auto layout = std::make_shared<QGridLayout>(window.get());
        layout->setSpacing(0); // Remove gaps to mimic a solid board
        bool colorCell = false;
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                auto rect = new QWidget();
                rect->setFixedSize(25, 25);
                if (colorCell) {
                    rect->setStyleSheet("background-color: black;");
                } else {
                    rect->setStyleSheet("background-color: white;");
                }
                layout->addWidget(rect, r, c);
                colorCell = !colorCell;
            }
            colorCell = !colorCell;
        }
        window->setWindowTitle("Exercise14_06");
        window->show();
        return app.exec();
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }
}