#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <iostream>
#include <exception>
#include <memory>

class CylinderWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(Qt::NoBrush);
        QPen solidPen(Qt::black);
        solidPen.setWidth(1);
        painter.setPen(solidPen);
        painter.drawEllipse(QPointF(150, 60), 70, 25);
        painter.drawArc(150 - 70, 200 - 25, 140, 50, 0 * 16, -180 * 16);
        QPen dashPen(Qt::black);
        dashPen.setDashPattern({6.0, 21.0}); 
        painter.setPen(dashPen);
        painter.drawArc(150 - 70, 200 - 25, 140, 50, 0 * 16, 180 * 16);
        painter.setPen(solidPen);
        painter.drawLine(150 - 70, 60, 150 - 70, 200); 
        painter.drawLine(150 + 70, 60, 150 + 70, 200);
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        QApplication app(argc, argv);
        auto window = std::make_shared<CylinderWidget>();
        
        window->setWindowTitle("Exercise14_10");
        window->resize(300, 250); 
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