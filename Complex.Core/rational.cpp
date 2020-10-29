#include "rational.h"

#include <numeric>
#include <sstream>

Rational::Rational() : Rational(0) {}

Rational::Rational(int64_t numerator, int64_t denominator) {
    if (denominator == 0) throw std::invalid_argument("Invalid argument");

    int gcd = std::gcd(numerator, denominator);
    numerator_ = numerator / gcd;
    denominator_ = denominator / gcd;

    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
}
Rational::Rational(int64_t numerator) {
    numerator_ = numerator;
    denominator_ = 1;
}
int64_t Rational::getNumerator() const {
    return numerator_;
}

int64_t Rational::getDenominator() const {
    return denominator_;
}

double Rational::toDouble() const {
    return numerator_ / (double)denominator_;
}

Rational& Rational::operator=(const Rational& other) {
    this->numerator_ = other.numerator_;
    this->denominator_ = other.denominator_;
    
    return *this;
}

bool Rational::operator==(const Rational& other) const {
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}
Rational Rational::operator+(const Rational& other) const {
    return { numerator_ * other.denominator_ + other.numerator_ * denominator_,
             denominator_ * other.denominator_ };
}
Rational Rational::operator*(const Rational& other) const {
    return { numerator_ * other.numerator_,
            denominator_ * other.denominator_ };
}
Rational Rational::operator/(const Rational& other) const {
    if (other.numerator_ == 0) throw std::domain_error("Division by zero");
    return { numerator_ * other.denominator_,
            denominator_ * other.numerator_ };
}
Rational Rational::operator-(const Rational& other) const {
    return *this + (-other);
}

Rational Rational::operator-() const {
    return Rational(-numerator_, denominator_);
}
std::ostream& operator<<(std::ostream& stream, const Rational& data) {
    stream << data.numerator_ << "/" << data.denominator_;
    return stream;
}
