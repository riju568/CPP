#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double get_real() const { return real; }
    double get_imag() const { return imag; }

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex multiply(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};

template <typename T>
class GenericMatrix {
protected:
    virtual T add(const T& o1, const T& o2) const = 0;
    virtual T multiply(const T& o1, const T& o2) const = 0;
    virtual T zero() const = 0;

public:
    virtual ~GenericMatrix() = default;
    using Matrix = std::vector<std::vector<T>>;
    Matrix addMatrix(const Matrix& m1, const Matrix& m2) const {
        if (m1.empty() || m2.empty() || m1.size() != m2.size() || m1[0].size() != m2[0].size()) {
            throw std::invalid_argument("Matrix addition error: Dimension mismatch.");
        }
        size_t rows = m1.size();
        size_t cols = m1[0].size();
        Matrix result(rows, std::vector<T>(cols, zero()));

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i][j] = add(m1[i][j], m2[i][j]);
            }
        }
        return result;
    }

    Matrix multiplyMatrix(const Matrix& m1, const Matrix& m2) const {
        if (m1.empty() || m2.empty() || m1[0].size() != m2.size()) {
            throw std::invalid_argument("Matrix multiplication error: Incompatible dimensions.");
        }

        size_t rows = m1.size();
        size_t cols = m2[0].size();
        size_t inner = m1[0].size();
        Matrix result(rows, std::vector<T>(cols, zero()));

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i][j] = zero();
                for (size_t k = 0; k < inner; ++k) {
                    result[i][j] = add(result[i][j], multiply(m1[i][k], m2[k][j]));
                }
            }
        }
        return result;
    }

    static void printResult(const Matrix& m1, const Matrix& m2, const Matrix& m3, char op) {
        size_t rows = m1.size();
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < m1[i].size(); ++j) std::cout << m1[i][j] << " ";
            if (i == rows / 2) std::cout << " " << op << " ";
            else std::cout << "   ";
            for (size_t j = 0; j < m2[i].size(); ++j) std::cout << m2[i][j] << " ";
            if (i == rows / 2) std::cout << " = ";
            else std::cout << "   ";
            for (size_t j = 0; j < m3[i].size(); ++j) std::cout << m3[i][j] << " ";
            std::cout << '\n';
        }
    }
};

class ComplexMatrix : public GenericMatrix<Complex> {
protected:
    Complex add(const Complex& c1, const Complex& c2) const override {
        return c1.add(c2);
    }
    Complex multiply(const Complex& c1, const Complex& c2) const override {
        return c1.multiply(c2);
    }

    Complex zero() const override {
        return Complex(0.0, 0.0);
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        ComplexMatrix complex_matrix;
        GenericMatrix<Complex>::Matrix m1 = {
            {Complex(1, 5), Complex(1, 6), Complex(1, 7)},
            {Complex(2, 5), Complex(1, 3), Complex(2, 7)},
            {Complex(3, 5), Complex(1, 2), Complex(3, 7)}
        };
        GenericMatrix<Complex>::Matrix m2 = {
            {Complex(1, 6), Complex(1, 7), Complex(1, 8)},
            {Complex(1, 3), Complex(2, 7), Complex(1, 4)},
            {Complex(1, 2), Complex(3, 7), Complex(3, 8)}
        };
        std::cout << "--- Matrix Addition ---\n";
        auto addition_result = complex_matrix.addMatrix(m1, m2);
        ComplexMatrix::printResult(m1, m2, addition_result, '+');

        std::cout << "\n--- Matrix Multiplication ---\n";
        auto multiplication_result = complex_matrix.multiplyMatrix(m1, m2);
        ComplexMatrix::printResult(m1, m2, multiplication_result, '*');
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }
    return 0;
}