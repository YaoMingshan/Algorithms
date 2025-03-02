#include "lt.h"

class Solution {
 public:
  int romanToInt(string s) {
    int val = 0;
    bool flag5 = false;
    bool flag50 = false;
    bool flag500 = false;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      switch (*it) {
        case 'I': {
          val += flag5 ? -1 : 1;
        } break;
        case 'V': {
          val += 5;
          flag5 = true;
        } break;
        case 'X': {
          val += flag50 ? -10 : 10;
          flag5 = true;
        } break;
        case 'L': {
          val += 50;
          flag50 = true;
        } break;
        case 'C': {
          val += flag500 ? -100 : 100;
          flag50 = true;
        } break;
        case 'D': {
          val += 500;
          flag500 = true;
        } break;
        case 'M': {
          val += 1000;
          flag500 = true;
        } break;
        default:
          break;
      }
    }

    return val;
  }
};

TEST(LeetCodeTest, lt13test) {
  Solution s;
  auto res = s.romanToInt("MCMXCIV");
  EXPECT_EQ(res, 1994);
}