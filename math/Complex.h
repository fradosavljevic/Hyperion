#ifndef HYPERION_COMPLEX_H
#define HYPERION_COMPLEX_H
#include <iosfwd>


class Complex {
public:
    Complex();
    Complex(float real, float imag);
    ~Complex() = default;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] float angle() const;
    [[nodiscard]] float getReal() const;
    [[nodiscard]] float getImaginary() const;
    [[nodiscard]] Complex conjugate() const;

    Complex& operator=(const Complex& c);
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator*(float c) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
private:
    float real;
    float imaginary;
};


#endif