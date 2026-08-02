#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <iostream>
#include <exception>
#include <memory>
#include <random>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        QApplication app(argc, argv);
        auto scene = std::make_shared<QGraphicsScene>();
        auto view = std::make_shared<QGraphicsView>(scene.get());
        QFont font("Times New Roman", 22, QFont::Bold, true);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        for(int i = 0; i < 5; i++) {
            auto text = scene->addText("Java", font);
            text->setDefaultTextColor(QColor(dis(gen), dis(gen), dis(gen), dis(gen)));
            text->setRotation(90);
            text->setPos(i * 50, 0); 
        }
        view->setWindowTitle("Exercise14_04");
        view->resize(300, 150);
        view->show();
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