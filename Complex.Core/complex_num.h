#pragma once
#include "rational.h"

class Complex {

public:
    Complex();
    Complex(Rational real, Rational imaginary);
    Complex(int64_t);
    Complex(int num);
    Complex(double num);
    Complex(int real, int imaginary);
    Complex(double real, double imaginary);
    explicit Complex(Rational real);

    friend std::ostream& operator<<(std::ostream& stream, const Complex& data);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex& operator=(const Complex& other);
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);
    Complex operator-() const;

    Rational getReal() const;
    Rational getImaginary() const;
    void setReal(Rational value);
    void setImaginary(Rational  value);

    Complex pow(int n) const;
    double arg() const;
    double abs() const;

private:
    Rational real_;
    Rational imaginary_;
};
