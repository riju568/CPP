#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <iostream>
#include <exception>
#include <memory>

class SmileyWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        double cx = 160.0;
        double cy = 160.0;
        double radius = 150.0;
        painter.setBrush(Qt::white);
        painter.setPen(QPen(Qt::black, 2));
        painter.drawEllipse(cx - radius, cy - radius, radius * 2, radius * 2);
        painter.save();
        painter.translate(cx, cy);
        painter.rotate(180);
        QPolygonF triangle;
        triangle << QPointF(0, 30) << QPointF(-30, -30) << QPointF(30, -30);
        painter.drawPolygon(triangle);
        painter.restore();
        painter.save();
        painter.translate(cx - 60, cy - 60);
        painter.rotate(90);
        painter.setBrush(Qt::NoBrush);
        painter.drawEllipse(QPointF(0, 0), radius / 6, radius / 5);
        painter.restore();
        painter.setBrush(Qt::black);
        painter.drawEllipse(QPointF(cx - 60, cy - 60), 16, 16);
        painter.save();
        painter.translate(cx + 60, cy - 60);
        painter.rotate(90);
        painter.setBrush(Qt::NoBrush);
        painter.drawEllipse(QPointF(0, 0), radius / 6, radius / 5);
        painter.restore();
        painter.setBrush(Qt::black);
        painter.drawEllipse(QPointF(cx + 60, cy - 60), 16, 16);
        painter.setBrush(Qt::NoBrush);
        painter.drawArc(cx - (radius - 60), 200 - (radius - 100), 
                        (radius - 60) * 2, (radius - 100) * 2, 0, -180 * 16);
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        QApplication app(argc, argv);
        auto window = std::make_shared<SmileyWidget>()
        window->setWindowTitle("Exercise14_11");
        window->resize(320, 320);
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