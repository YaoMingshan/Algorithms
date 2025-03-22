#include "lt.h"

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = record.find(nums[i]);
      if (it != record.end()) {
        if (i - it->second <= k) {
          return true;
        } else {
          it->second = i;
        }
      } else {
        record[nums[i]] = i;
      }
    }
    return false;
  }
};

TEST(LeetCodeTest, lt219test) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1};
  int k = 3;
  EXPECT_TRUE(solution.containsNearbyDuplicate(nums, k));
  nums = {1, 0, 1, 1};
  k = 1;
  EXPECT_TRUE(solution.containsNearbyDuplicate(nums, k));
  nums = {1, 2, 3, 1, 2, 3};
  k = 2;
  EXPECT_FALSE(solution.containsNearbyDuplicate(nums, k));
}