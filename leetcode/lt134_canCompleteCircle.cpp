#include "gtest/gtest.h"

#include <stack>
#include <vector>

using namespace std;
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if (gas.size() == 1) return gas.at(0) >= cost.at(0) ? 0 : -1;
    int maxOil = 0;
    int start = -1;
    int oilSt = 0;
    for (int i = gas.size() - 1; i >= 0; i--) {
      int curOil = gas.at(i);
      oilSt += curOil - cost.at(i);
      if (oilSt >= maxOil) {
        maxOil = oilSt;
        start = i;
      }
    }

    int collect = 0;
    for (int i = 0; i < gas.size(); ++i) {
      collect +=
          gas.at((i + start) % gas.size()) - cost.at((i + start) % gas.size());
      if (collect < 0) return -1;
    }
    return start;
  }
};

TEST(LeetCodeTest, lt134test) {}
