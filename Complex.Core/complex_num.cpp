#include "complex_num.h"
#include <exception>

Complex::Complex() : Complex((int64_t)0) {}

Complex::Complex(int64_t num) : Complex(Rational(num)) {}

Complex::Complex(int num) : Complex((int64_t)num) {}

Complex::Complex(int real, int imaginary) : Complex(Rational(real), Rational(imaginary)) {}

Complex::Complex(const Rational& real) {
    real_ = real;
    imaginary_ = 0;
}

Complex::Complex(double num) {
    int64_t x = 100'000'000;
    real_ = Rational(x * num, x);
    imaginary_ = 0;
}

Complex::Complex(const Rational& real, const Rational& imaginary) {
    real_ = real;
    imaginary_ = imaginary;
}

Complex::Complex(double real, double imaginary) {
    int64_t x = 100'000'000;
    real_ = Rational(x * real, x);
    imaginary_ = Rational(x * imaginary, x);
}

Rational Complex::getImaginary() const {
    return imaginary_;
}

Rational Complex::getReal() const {
    return real_;
}

void Complex::setReal(Rational value) {
    real_ = value;
}

void Complex::setImaginary(Rational value) {
    imaginary_ = value;
}

Complex Complex::pow(int n) const
{
    Complex new_complex = *this;
    for (size_t i = 2; i <= n; i++)
    {
        new_complex *= new_complex;
    }

    return new_complex;
}

double Complex::arg() const {
    return atan((imaginary_ / real_).toDouble());
}

double Complex::abs() const {
    return sqrt((real_ * real_ + imaginary_ * imaginary_).toDouble());
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real_ + other.getReal(),
        imaginary_ + other.getImaginary());
}

Complex Complex::operator-(const Complex& other) const {
    return *this + (-other);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real_ * other.getReal() - imaginary_ * other.getImaginary(),
        real_ * other.getImaginary() + imaginary_ * other.getReal());
}

Complex Complex::operator/(const Complex& other) const {
    Rational divider = other.getReal() * other.getReal() - -(other.getImaginary() * other.getImaginary());
    Complex temp = *this * Complex(other.getReal(), -other.getImaginary());

    if (divider == 0) throw std::invalid_argument("Division by zero");

    return Complex(temp.getReal() / divider, temp.getImaginary() / divider);
}

Complex& Complex::operator=(const Complex& other) {
    real_ = other.getReal();
    imaginary_ = other.getImaginary();
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-this->getReal(), -this->getImaginary());
}

bool Complex::operator==(const Complex& other) const {
    return real_ == other.getReal() && imaginary_ == other.getImaginary();
}

bool Complex::operator!=(const Complex& other) const {
    return !this->operator==(other);
}


Complex& Complex::operator+=(const Complex& other) {
    *this = *this + other;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    *this = *this - other;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}
Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Complex& complex) {
    stream << complex.getReal();
    if (complex.getImaginary().getNumerator() != 0) {
        stream << " + " << complex.getImaginary() << "i";
    }

    return stream;
}
