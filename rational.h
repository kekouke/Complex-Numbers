#pragma once
#include <numeric>
#include <sstream>
#include <algorithm>

class Rational {
 public:
  Rational();
  Rational(int numerator, int denominator);

  int getNumerator() const;
  int getDenominator() const;

  bool operator==(const Rational& other) const;
  Rational operator+(const Rational& other) const;
  Rational operator-(const Rational& other) const;
  Rational operator-() const;
  Rational operator*(const Rational& other) const;
  Rational operator/(const Rational& other);
  bool operator<(const Rational& other) const;
  bool operator>(const Rational& other) const;
  friend std::istream& operator>>(std::istream& stream, Rational& data);
  friend std::ostream& operator<<(std::ostream& stream, const Rational& data);

 private:
  int numerator_;
  int denominator_;
};
