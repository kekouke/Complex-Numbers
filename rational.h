#pragma once
#include <numeric>
#include <sstream>
#include <algorithm>

class Rational {
 public:
  Rational();
  Rational(int64_t numerator, int64_t denominator);

  int64_t getNumerator() const;
  int64_t getDenominator() const;
  double toDouble() const;

  bool operator==(const Rational& other) const;
  Rational operator+(const Rational& other) const;
  Rational operator-(const Rational& other) const;
  Rational operator-() const;
  Rational operator*(const Rational& other) const;
  Rational operator/(const Rational& other) const;
  bool operator<(const Rational& other) const;
  bool operator>(const Rational& other) const;
  friend std::ostream& operator<<(std::ostream& stream, const Rational& data);

 private:
  int64_t numerator_;
  int64_t denominator_;
};
