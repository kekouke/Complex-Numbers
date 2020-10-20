#include "complex_num.h"

Complex::Complex(Rational real, Rational imaginary) {
  real_ = real;
  imaginary_ = imaginary;
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
  Rational div = other.getReal() * other.getReal() - other.getImaginary() * other.getImaginary(); // знаменатель
  Complex temp = *this * Complex(other.getReal(), -other.getImaginary()); // числитель
  return Complex(temp.getReal() / div, temp.getImaginary() / div);
}

Complex& Complex::operator=(const Complex &other) {
  real_ = other.getReal();
  imaginary_ = other.getImaginary();
  return *this; // ???
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

//TODO
/*Complex& Complex::operator+=(const Complex &other) {
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
  return *this;
}*/
//

std::ostream& operator<<(std::ostream& stream, const Complex& complex) {
  stream << complex.getReal() << " " << complex.getImaginary();
  return stream;
}

std::istream& operator>>(std::istream& stream, Complex& complex) {
  Rational real;
  Rational imaginary;
  stream >> real >> imaginary;
  complex.setReal(real);
  complex.setImaginary(imaginary);
  return stream;
}
