#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <iostream>
#include <exception>
#include <memory>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        QApplication app(argc, argv);
        auto scene = std::make_shared<QGraphicsScene>();
        auto view = std::make_shared<QGraphicsView>(scene.get());
        QString message = "WELCOME TO JAVA";
        QFont font("Times New Roman", 28, QFont::Bold);
        double radius = 75.0;
        for(int i = 0; i < message.length(); ++i) {
            double currentAngle = i * 22.0;
            double rotation = 90.0 + currentAngle;
            double rad = currentAngle * M_PI / 180.0; 
            double x = 105.0 + radius * std::cos(rad);
            double y = 105.0 + radius * std::sin(rad);
            auto text = scene->addText(QString(message[i]), font);
            text->setRotation(rotation);
            text->setPos(x, y);
        }
        view->setWindowTitle("Exercise14_05");
        view->resize(250, 250);
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