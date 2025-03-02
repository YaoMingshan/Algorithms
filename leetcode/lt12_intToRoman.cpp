#include "lt.h"

class Solution {
 public:
  string intToRoman(int num) {
    std::string res;
    int thousands = num / 1000;
    int handreds = (num - thousands * 1000) / 100;
    int tens = (num - thousands * 1000 - handreds * 100) / 10;
    int ones = num % 10;
    for (int i = 0; i < thousands; ++i) res += "M";

    if (handreds == 5) res += "D";
    else if (handreds == 4) res += "CD";
    else if (handreds == 9) res += "CM";
    else if (handreds < 4) {
      for (int i = 0; i < handreds; ++i) res += "C";
    } else {
      res += "D";
      for (int i = 0; i < handreds - 5; ++i) res += "C";
    }

    if (tens == 5) res += "L";
    else if (tens == 4) res += "XL";
    else if (tens == 9) res += "XC";
    else if (tens < 4) {
      for (int i = 0; i < tens; ++i) res += "X";
    } else {
      res += "L";
      for (int i = 0; i < tens - 5; ++i) res += "X";
    }

    if (ones == 5) res += "V";
    else if (ones == 4) res += "IV";
    else if (ones == 9) res += "IX";
    else if (ones < 4) {
      for (int i = 0; i < ones; ++i) res += "I";
    } else {
      res += "V";
      for (int i = 0; i < ones - 5; ++i) res += "I";
    }

    return res;
  }
};

TEST(LeetCodeTest, lt12test) {
  Solution s;
  auto res = s.intToRoman(1994);
  EXPECT_EQ(res, "MCMXCIV");
}