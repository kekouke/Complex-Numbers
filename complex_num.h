#pragma once
#include "rational.h"

class Complex {

 public:
  Complex(Rational real, Rational imaginary);
  Complex operator+(const Complex& other) const;
  Complex operator-(const Complex& other) const;
  Complex operator*(const Complex& other) const;
  Complex operator/(const Complex& other) const;
  Complex& operator=(const Complex& other);
  bool operator==(const Complex& other) const;
  bool operator!=(const Complex& other) const;
/*  Complex& operator+=(const Complex& other);
  Complex& operator-=(const Complex& other);
  Complex& operator*=(const Complex& other);
  Complex& operator/=(const Complex& other);*/
  Complex operator-() const;

  Rational getReal() const;
  Rational getImaginary() const;
  void setReal(Rational value);
  void setImaginary(Rational  value);

 private:
  Rational real_;
  Rational imaginary_;
};
