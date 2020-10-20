#include "rational.h"

#include <numeric>
#include <sstream>

Rational::Rational() {
  numerator_ = 0;
  denominator_ = 1;
}
Rational::Rational(int numerator, int denominator) {
  if (denominator == 0) throw std::invalid_argument("Invalid argument");

  int gcd = std::gcd(numerator, denominator);
  numerator_  = numerator / gcd;
  denominator_ = denominator / gcd;

  if (denominator_ < 0) {
    denominator_ = -denominator_;
    numerator_ = -numerator_;
  }
}
int Rational::getNumerator() const{
  return numerator_;
}

int Rational::getDenominator() const {
  return denominator_;
}

bool Rational::operator==(const Rational& other) const {
  return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}
Rational Rational::operator+(const Rational &other) const {
  return { numerator_ * other.denominator_ + other.numerator_ * denominator_,
           denominator_ * other.denominator_};
}
Rational Rational::operator*(const Rational& other) const {
  return {numerator_ * other.numerator_,
          denominator_ * other.denominator_};
}
Rational Rational::operator/(const Rational& other) {
  if (numerator_ == 0) throw std::domain_error("Division by zero");
  return { numerator_ * other.denominator_,
          denominator_ * other.numerator_};
}
Rational Rational::operator-(const Rational &other) const {
  return *this + (-other);
}

Rational Rational::operator-() const {
  return Rational(-numerator_, denominator_);
}
bool Rational::operator<(const Rational& other) const {
  return (*this - other).getNumerator() < 0;
}
bool Rational::operator>(const Rational& other) const {
  return (*this - other).getNumerator() > 0;
}
std::istream& operator>>(std::istream& stream, Rational& data) { // TODO
  int num, denom;
  char slash;
  stream >> num >> slash >> denom;
  if (!stream.fail() && slash =='/') {
    data.numerator_ = num / std::gcd(denom, num);
    data.denominator_ =  denom / std::gcd(denom, num);
  }
  return stream;
}
std::ostream& operator<<(std::ostream& stream, const Rational& data) {
  stream << data.numerator_ << "/" << data.denominator_;
  return stream;
}
