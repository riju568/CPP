#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include <exception>
#include <memory>


QVBoxLayout* createBarBox(const QString& labelText, const QString& color, double percent) {
    auto box = new QVBoxLayout();
    box->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    auto label = new QLabel(labelText);
    label->setAlignment(Qt::AlignCenter);
    auto bar = new QWidget();
    double fullBarValue = 250.0; 
    bar->setFixedSize(125, fullBarValue * percent);
    bar->setStyleSheet(QString("background-color: %1;").arg(color));
    box->addWidget(label);
    box->addWidget(bar);
    return box;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        QApplication app(argc, argv);
        auto window = std::make_shared<QWidget>();
        auto hBox = std::make_shared<QHBoxLayout>(window.get());
        hBox->setSpacing(5);
        hBox->setContentsMargins(10, 10, 10, 10);
        hBox->setAlignment(Qt::AlignBottom | Qt::AlignHCenter); // Align bottoms[cite: 7]
        hBox->addLayout(createBarBox("Project -- 20%", "red", 0.2));
        hBox->addLayout(createBarBox("Quiz -- 10%", "blue", 0.1));
        hBox->addLayout(createBarBox("Midterm -- 30%", "green", 0.3));
        hBox->addLayout(createBarBox("Final -- 40%", "orange", 0.4));
        window->setWindowTitle("Exercise14_12");
        window->setFixedSize(550, 300); // Fixed size replaces setResizable(false)[cite: 7]
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