#include "complex_num.h"

Complex::Complex() {
    real_ = 0;
    imaginary_ = 0;
}

Complex::Complex(Rational real, Rational imaginary) {
  real_ = real;
  imaginary_ = imaginary;
}

Complex::Complex(int64_t num) {
    real_ = num;
    imaginary_ =  0;
}

Complex::Complex(Rational real) {
    real_ = real;
    imaginary_ = 0;
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

Complex Complex::operator+(const Complex &other) const {
  return Complex(real_ + other.getReal(),
                 imaginary_ + other.getImaginary());
}

Complex Complex::operator-(const Complex &other) const {
  return *this + (-other);
}

Complex Complex::operator*(const Complex &other) const {
  return Complex(real_ * other.getReal() - imaginary_ * other.getImaginary(),
                 real_ * other.getImaginary() + imaginary_ * other.getReal());
}

Complex Complex::operator/(const Complex &other) const {
  Rational div = other.getReal() * other.getReal() - -(other.getImaginary() * other.getImaginary()); // знаменатель - (Big_Integer)
  Complex temp = *this * Complex(other.getReal(), -other.getImaginary()); // числитель
  return Complex(temp.getReal() / div, temp.getImaginary() / div); // Передавать RTIONAL ИЗ ДВУХ ЧИСЕЛ
}

Complex& Complex::operator=(const Complex &other) {
  real_ = other.getReal();
  imaginary_ = other.getImaginary();
  return *this;
}

Complex Complex::operator-() const {
  return Complex(-this->getReal(), -this->getImaginary());
}

bool Complex::operator==(const Complex &other) const {
  return real_ == other.getReal() && imaginary_ == other.getImaginary();
}

bool Complex::operator!=(const Complex &other) const {
  return !this->operator==(other);
}


Complex& Complex::operator+=(const Complex &other) {
  this->real_ = this->real_ + other.getReal();
  this->imaginary_ = this->imaginary_+ other.getImaginary();
  return *this;
}

Complex &Complex::operator-=(const Complex &other) {
  this->real_ = this->real_ - other.getReal();
  this->imaginary_ = this->imaginary_ - other.getImaginary();
  return *this;
}

Complex &Complex::operator*=(const Complex &other) {
  *this = *this * other;
  return *this;
}
Complex &Complex::operator/=(const Complex &other) {
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
