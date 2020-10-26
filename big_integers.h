#pragma once

#include <vector>
#include <string>

class Big_Integers {
 public:
  Big_Integers();
  explicit Big_Integers(std::string num);
  explicit Big_Integers(std::vector<int> num);
  bool operator==(const Big_Integers& other) const;
  Big_Integers operator+(const Big_Integers& other) const;
  Big_Integers operator-(const Big_Integers& other) const;
  Big_Integers operator-() const;
  Big_Integers operator*(const Big_Integers& other) const;
  Big_Integers operator/(const Big_Integers& other);
  Big_Integers& operator=(const Big_Integers& other);

  std::string getNumber() const;
  std::vector<int> getVector() const;

 private:
  bool isNegaive_;
  std::vector<int> big_integer_;
};