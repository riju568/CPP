#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <iostream>
#include <exception>
#include <memory>
#include <random>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        QApplication app(argc, argv);
        auto window = std::make_shared<QWidget>();
        auto layout = std::make_shared<QGridLayout>(window.get());
        QPixmap pixX("resources/tictactoe/x.png");
        QPixmap pixO("resources/tictactoe/o.png");
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 1);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                auto label = new QLabel();
                if (distrib(gen)) {
                    label->setPixmap((distrib(gen) ? pixX : pixO).scaled(100, 100, Qt::KeepAspectRatio));
                }
                layout->addWidget(label, i, j);
            }
        }

        window->setWindowTitle("Exercise14_02");
        window->resize(315, 315);
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