#include <stack>
#include <vector>

#include "gtest/gtest.h"

using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    int left = 0;
    int right = 1;
    for (; right < nums.size(); right++) {
      if (nums.at(right) != nums.at(right - 1)) {
        left++;
        nums.at(left) = nums.at(right);
      }
    }
    return left + 1;
  }
};

TEST(LeetCodeTest, lt26test) {}
