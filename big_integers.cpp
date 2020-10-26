#include "big_integers.h"
#include <cstdlib>
#include <utility>

// Реализовать работу с отрицательными числами
// Реализовтаь операцию деления
// Реализовать операцию взятия остатка
// Внедрить данный класс в класс рациональных чисел


Big_Integers::Big_Integers()
= default; //TODO

Big_Integers::Big_Integers(std::string num) {
    for (size_t i = num.length();  i > 0; i--) {
        big_integer_.push_back((int) (num[i - 1] - '0'));
    }
    isNegaive_ = false;
}

Big_Integers::Big_Integers(std::vector<int> num) : big_integer_(std::move(num)) {}

Big_Integers& Big_Integers::operator=(const Big_Integers& other)
{
    this->big_integer_ = other.big_integer_;
    return *this;
}

std::string Big_Integers::getNumber() const {
  if (big_integer_.empty()) {
    return "0";
  }

  std::string number;
  for (size_t i = big_integer_.size(); i > 0; i--) {
    number += std::to_string(big_integer_[i - 1]);
  }

  return number;
}

std::vector<int> Big_Integers::getVector() const
{
    return big_integer_;
}

bool Big_Integers::operator==(const Big_Integers &other) const {
  if (isNegaive_ != other.isNegaive_) {
    return false;
  }

  if (big_integer_.size() != other.big_integer_.size()) {
    return false;
  }

  for (size_t i = 0; i < big_integer_.size(); i++) {
    if (big_integer_[i] != other.big_integer_[i]) {
      return false;
    }
  }

  return true;
}

Big_Integers Big_Integers::operator+(const Big_Integers& other) const {
    if (isNegaive_) {
        if (other.isNegaive_) {
            return -(-(*this) + -(other));
        } else {
            return other - (-*this);
        }
    } else if (other.isNegaive_) {
        return *this - (-other);
    } else {
        std::vector<int> lhs = this->big_integer_;
        const std::vector<int>& rhs = other.big_integer_;
        int carry = 0;
        for (size_t i = 0; i < std::max(lhs.size(), rhs.size()) || carry; i++) {
            if (i == lhs.size()) {
                lhs.push_back(0);
            }

            lhs[i] += carry + (i < rhs.size() ? rhs[i] : 0);

            carry = lhs[i] > 9;
            if (carry) {
                lhs[i] -= 10;
            }
        }
        return Big_Integers(lhs);
    }
}

Big_Integers Big_Integers::operator-(const Big_Integers& other) const { // Only for a >= b
    std::vector<int> lhs = this->big_integer_;
    const std::vector<int>& rhs = other.big_integer_;
    int carry = 0;

    for (size_t i = 0; i < rhs.size() || carry; i++) {
        lhs[i] -= carry + (i < rhs.size() ? rhs[i] : 0);

        carry = lhs[i] < 0;
        if (carry) {
            lhs[i] += 10;
        }
    }

    while (lhs.size() > 1 && lhs.back() == 0) {
        lhs.pop_back();
    }

    return Big_Integers(lhs);
}

Big_Integers Big_Integers::operator-() const
{
    Big_Integers new_integer = *this;
    new_integer.isNegaive_ = !new_integer.isNegaive_;

    return new_integer;
}

Big_Integers Big_Integers::operator*(const Big_Integers& other) const {
    const std::vector<int>& lhs = this->big_integer_;
    const std::vector<int>& rhs = other.big_integer_;
    std::vector<int> result(lhs.size() + rhs.size());

    for (size_t i = 0; i < lhs.size(); i++) {
        for (size_t j = 0, carry = 0; j < rhs.size() || carry; j++) {
            int64_t current = (int)carry + (int64_t) lhs[i] * (j < rhs.size() ? rhs[j] : 0);
            current += result[i + j];
            result[i + j] = current % 10;
            carry = current / 10;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return Big_Integers(result);
}

