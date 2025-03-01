#include "gtest/gtest.h"

#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    std::vector<int> prodect(nums.size(), 1);
    int left = 0;
    int right = nums.size() - 1;
    int lp = 1, rp = 1;
    for (int i = 0; i < nums.size(); ++i) {
      prodect.at(left) *= lp;
      prodect.at(right) *= rp;
      lp *= nums.at(left);
      rp *= nums.at(right);
      left++;
      right--;
    }
    return prodect;
  }
};

TEST(LeetCodeTest, lt238test) {}
