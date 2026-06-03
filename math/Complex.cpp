#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() {
    this->real = 0.0f;
    this->imaginary = 0.0f;
}

Complex::Complex(const float real, const float imag) {
    this->real = real;
    this->imaginary = imag;
}

float Complex::magnitude() const {
    return std::sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

float Complex::angle() const {
    return std::atan2(this->imaginary, this->real);
}

float Complex::getReal() const {
    return this->real;
}

float Complex::getImaginary() const {
    return this->imaginary;
}

Complex Complex::conjugate() const {
    return {this->real, - this->imaginary};
}

Complex &Complex::operator=(const Complex &c) {
    if (this != &c) {
        this->real = c.real;
        this->imaginary = c.imaginary;
    }
    return *this;
}

Complex Complex::operator+(const Complex &c) const {
    return {this->real + c.real, this->imaginary + c.imaginary};
}

Complex Complex::operator-(const Complex &c) const {
    return {this->real - c.real, this->imaginary - c.imaginary};
}

Complex Complex::operator*(const Complex& c) const {
    return {this->real * c.real - this->imaginary * c.imaginary, this->real * c.imaginary + this->imaginary * c.real};
}

Complex Complex::operator*(const float c) const {
    return {this->real * c, this->imaginary * c};
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + i" << c.imaginary;
    return os;
}
