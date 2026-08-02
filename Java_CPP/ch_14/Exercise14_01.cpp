#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
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
        QString images[4] = {
            "resources/Space_Man_Moon_Man.png", 
            "resources/GettyImages-10.png", 
            "resources/flyer1.jpg", 
            "resources/fintech-pic.jpg"
        };
        int positions[4][2] = {{0, 1}, {2, 4}, {0, 4}, {2, 1}}; 
        for (int i = 0; i < 4; ++i) {
            auto label = new QLabel(); 
            QPixmap pix(images[i]);
            label->setPixmap(pix.scaled(300, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            layout->addWidget(label, positions[i][0], positions[i][1]);
        }

        window->setLayout(layout.get());
        window->setWindowTitle("Exercise14_01");
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