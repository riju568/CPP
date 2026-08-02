#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <iostream>
#include <exception>
#include <memory>

class FanWidget : public QWidget {
public:
    FanWidget() {
        setMinimumSize(220, 220);    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(Qt::white);
        painter.setPen(Qt::black);
        painter.drawEllipse(10, 10, 200, 200); 
        painter.setBrush(Qt::gray);
        painter.setPen(Qt::NoPen);
        int angle = 120;
        int numArcs = 4;
        while (numArcs > 0) {
            painter.drawPie(30, 30, 160, 160, angle * 16, 35 * 16);
            numArcs--;
            angle += 90;
        }
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        QApplication app(argc, argv);
        auto window = std::make_shared<QWidget>();
        auto grid = std::make_shared<QGridLayout>(window.get());
        grid->setContentsMargins(10, 10, 10, 10);
        grid->setHorizontalSpacing(10);
        grid->setVerticalSpacing(10);
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                grid->addWidget(new FanWidget(), i, j);
            }
        }
        window->setWindowTitle("Exercise14_09");
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