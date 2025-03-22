#include "lt.h"

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;
    for (int num : numSet) {
      if (numSet.find(num - 1) == numSet.end()) {
        int currentNum = num;
        int currentStreak = 1;
        while (numSet.find(currentNum + 1) != numSet.end()) {
          currentNum += 1;
          currentStreak += 1;
        }
        longestStreak = max(longestStreak, currentStreak);
      }
    }
    return longestStreak;
  }
};

TEST(LeetCodeTest, lt128test) {
  Solution solution;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  EXPECT_EQ(solution.longestConsecutive(nums), 4);
  nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  EXPECT_EQ(solution.longestConsecutive(nums), 9);
}