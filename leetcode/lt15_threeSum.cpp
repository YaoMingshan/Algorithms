#include "lt.h"

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          result.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
          while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
          left++;
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }
    return result;
  }
};

TEST(LeetCodeTest, lt15test) {
  Solution sol;
  vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> expected1 = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(sol.threeSum(nums1), expected1);
  vector<int> nums2 = {0, 0, 0, 0};
  vector<vector<int>> expected2 = {{0, 0, 0}};
  EXPECT_EQ(sol.threeSum(nums2), expected2);
}