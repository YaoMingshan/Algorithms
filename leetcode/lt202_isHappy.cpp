#include "lt.h"

class Solution {
 public:
  bool isHappy(int n) {
    unordered_map<int, int> record;
    while (n != 1) {
      int nextN = 0;
      int copy = n;
      while (copy > 0) {
        nextN += (copy % 10) * (copy % 10);
        copy = copy / 10;
      }
      if (record.find(n) != record.end())
        return false;
      else
        record[n] = nextN;
      n = nextN;
    }
    return true;
  }
};

TEST(LeetCodeTest, lt202test) {
  Solution solution;
  int n = 19;
  EXPECT_TRUE(solution.isHappy(n));
  n = 2;
  EXPECT_FALSE(solution.isHappy(n));
}