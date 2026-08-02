#include <QApplication>
#include <QGridLayout>
#include <QLineEdit>
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
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        for (int r = 0; r < 10; r++) {
            for (int c = 0; c < 10; c++) {
                auto textField = new QLineEdit();
                textField->setText(QString::number(dis(gen)));
                textField->setAlignment(Qt::AlignCenter);
                textField->setMaximumWidth(30);
                
                layout->addWidget(textField, r, c);
            }
        }
        window->setWindowTitle("Exercise14_07");
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