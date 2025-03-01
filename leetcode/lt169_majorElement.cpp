#include "gtest/gtest.h"

#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int val = 0;
    int count = 0;
    for (int right = 0; right < nums.size(); right++) {
      if (count == 0) {
        val = nums.at(right);
        count++;
        continue;
      }
      if (nums.at(right) == val) {
        count++;
      } else {
        count--;
      }
    }
    return val;
  }
};

TEST(LeetCodeTest, lt169test) {}
