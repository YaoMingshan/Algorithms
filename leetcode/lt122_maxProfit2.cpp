#include "gtest/gtest.h"

#include <stack>
#include <vector>

using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int profit = 0;
    for (int i = prices.size() - 2; i >= 0; i--) {
      if (prices.at(i + 1) > prices.at(i)) {
        profit += prices.at(i + 1) - prices.at(i);
      }
    }
    return profit;
  }
};

TEST(LeetCodeTest, lt122test) {}
