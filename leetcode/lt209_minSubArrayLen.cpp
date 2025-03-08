#include "lt.h"

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int minLength = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < n; ++right) {
      sum += nums[right];
      while (sum >= target) {
        minLength = min(minLength, right - left + 1);
        sum -= nums[left];
        left++;
      }
    }
    return minLength == INT_MAX ? 0 : minLength;
  }
};

TEST(LeetCodeTest, lt209test) {
  Solution sol;
  vector<int> nums1 = {2, 3, 1, 2, 4, 3};
  int target1 = 7;
  EXPECT_EQ(sol.minSubArrayLen(target1, nums1), 2);
  vector<int> nums2 = {1, 4, 4};
  int target2 = 4;
  EXPECT_EQ(sol.minSubArrayLen(target2, nums2), 1);
  vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
  int target3 = 11;
  EXPECT_EQ(sol.minSubArrayLen(target3, nums3), 0);
}
