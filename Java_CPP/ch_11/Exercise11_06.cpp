#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <exception>

class Printable {
public:
    virtual ~Printable() = default;
    [[nodiscard]] virtual std::string toString() const = 0;
};

class Loan : public Printable {
public:
    [[nodiscard]] std::string toString() const override {
        return "Loan Object [Default Terms]";
    }
};

class Date : public Printable {
public:
    [[nodiscard]] std::string toString() const override {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        char buf[100];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string("Date: ") + buf;
    }
};

class StringItem : public Printable {
private:
    std::string text;
public:
    explicit StringItem(std::string str) : text(std::move(str)) {}
    [[nodiscard]] std::string toString() const override {
        return text;
    }
};

class Circle : public Printable {
public:
    [[nodiscard]] std::string toString() const override {
        return "Circle Object [Radius: 1.0]";
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::vector<std::unique_ptr<Printable>> list;
        list.push_back(std::make_unique<Loan>());
        list.push_back(std::make_unique<Date>());
        list.push_back(std::make_unique<StringItem>("stringTest"));
        list.push_back(std::make_unique<Circle>());
        for (const auto& item : list) {
            if (item) {
                std::cout << item->toString() << '\n';
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}