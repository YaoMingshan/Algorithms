#include "lt.h"

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int max_area = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      int current_height = min(height[left], height[right]);
      int current_width = right - left;
      int current_area = current_height * current_width;
      max_area = max(max_area, current_area);
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return max_area;
  }
};

TEST(LeetCodeTest, lt11test) {
  Solution sol;
  vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  EXPECT_EQ(sol.maxArea(height1), 49);
  vector<int> height2 = {1, 1};
  EXPECT_EQ(sol.maxArea(height2), 1);
} 