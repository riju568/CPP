#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <iostream>
#include <exception>
#include <memory>

class PieChartWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        double width = 350, height = 350;
        double cx = width / 2;
        double cy = height / 2;
        double radius = 150;
        double nextSliceStart = 0;
        QRectF rect(cx - radius, cy - radius, radius * 2, radius * 2);
        painter.setBrush(Qt::white);
        painter.setPen(Qt::black);
        painter.drawEllipse(rect);
        double w20 = 0.2 * 360;
        painter.setBrush(Qt::red);
        painter.setPen(Qt::red);
        painter.drawPie(rect, nextSliceStart * 16, w20 * 16);
        painter.setPen(Qt::black);
        painter.drawText(cx + 25, cy - 15, "Project -- 20%");
        nextSliceStart += w20;
        double w10 = 0.1 * 360;
        painter.setBrush(Qt::blue);
        painter.setPen(Qt::blue);
        painter.drawPie(rect, nextSliceStart * 16, w10 * 16);
        painter.setPen(Qt::black);
        painter.drawText(cx + 15, cy - (radius + 10), "Quizzes -- 10%");
        nextSliceStart += w10;
        double w30 = 0.3 * 360;
        painter.setBrush(Qt::green);
        painter.setPen(Qt::green);
        painter.drawPie(rect, nextSliceStart * 16, w30 * 16);
        painter.setPen(Qt::black);
        painter.drawText(cx - 135, cy, "MidTerm -- 30%");
        nextSliceStart += w30;
        double w40 = 0.4 * 360;
        painter.setBrush(QColor(255, 165, 0)); // Orange[cite: 8]
        painter.setPen(QColor(255, 165, 0));
        painter.drawPie(rect, nextSliceStart * 16, w40 * 16);
        painter.setPen(Qt::black);
        painter.drawText(cx + 15, cy + (radius - 15), "Finals -- 40%");
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        QApplication app(argc, argv);
        auto window = std::make_shared<PieChartWidget>();
        window->setWindowTitle("Exercise14_13");
        window->resize(350, 350); 
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