#include "lt.h"

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
      int complement = target - nums[i];
      if (numMap.find(complement) != numMap.end()) {
        return {numMap[complement], i};
      }
      numMap[nums[i]] = i;
    }
    return {};  // No solution found
  }
};

TEST(LeetCodeTest, lt1test) {
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> expected = {0, 1};
  EXPECT_EQ(solution.twoSum(nums, target), expected);
}