#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <iostream>
#include <exception>
#include <memory>
#include <random>
#include <vector>
#include <numeric>
#include <algorithm>

class CardWindow : public QWidget {
public:
    CardWindow() {
        auto mainLayout = new QVBoxLayout(this);
        cardLayout = new QHBoxLayout();
        auto buttonLayout = new QHBoxLayout();

        auto refreshBtn = new QPushButton("Refresh");
        buttonLayout->addWidget(refreshBtn, 0, Qt::AlignCenter);

        mainLayout->addLayout(cardLayout);
        mainLayout->addLayout(buttonLayout);

        connect(refreshBtn, &QPushButton::clicked, this, &CardWindow::refreshCards);
        refreshCards(); 
    }

private:
    QHBoxLayout* cardLayout;
    
    void refreshCards() {
        QLayoutItem *child;
        while ((child = cardLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        std::vector<int> deck(52);
        std::iota(deck.begin(), deck.end(), 1); 
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
        for (int i = 0; i < 3; ++i) {
            auto label = new QLabel();
            QPixmap pix(QString("resources/cards/%1.png").arg(deck[i]));
            label->setPixmap(pix.scaledToHeight(300, Qt::SmoothTransformation));
            cardLayout->addWidget(label);
        }
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        QApplication app(argc, argv);
        auto window = std::make_shared<CardWindow>();
        
        window->setWindowTitle("Exercise14_03");
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