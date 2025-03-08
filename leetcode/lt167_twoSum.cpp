#include "lt.h"

  class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int left = 0, right = numbers.size() - 1;
      while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
          return {left + 1, right + 1};  // 1-based index
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
      return {};  // No solution found, though the problem guarantees one.
    }
  };

TEST(LeetCodeTest, lt167test) {
  Solution solution;
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  EXPECT_EQ(solution.twoSum(numbers, target), vector<int>({1, 2}));
}