#include "gtest/gtest.h"

#include <stack>
#include <vector>

using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int profit = 0;
    int max = prices.at(prices.size() - 1);
    int min = prices.at(prices.size() - 2);
    for (int i = prices.size() - 2; i >= 0; i--) {
      if (prices.at(i) < min) {
        min = prices.at(i);
      }
      if (prices.at(i) > max) {
        max = prices.at(i);
        min = max;
      }
      if (max - min > profit) {
        profit = max - min;
      }
    }
    return profit;
  }
};

TEST(LeetCodeTest, lt121test) {}
