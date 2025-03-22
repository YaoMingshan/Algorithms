#include "lt.h"

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int start = 0;
    while (start < nums.size()) {
      if (start + 1 >= nums.size()) {
        res.push_back(to_string(nums[start]));
        break;
      }
      int end = start + 1;
      while (end < nums.size() && nums[end] == nums[end - 1] + 1) {
        end += 1;
      }
      if (end > start + 1) {
        res.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
      } else {
        res.push_back(to_string(nums[start]));
      }
      start = end;
    }
    return res;
  }
};

TEST(LeetCodeTest, lt228test) {
  Solution solution;
  vector<int> nums = {0, 1, 2, 4, 5, 7};
  vector<string> expected = {"0->2", "4->5", "7"};
  EXPECT_EQ(solution.summaryRanges(nums), expected);
  nums = {0, 2, 3, 4, 6, 8, 9};
  expected = {"0", "2->4", "6", "8->9"};
  EXPECT_EQ(solution.summaryRanges(nums), expected);
}