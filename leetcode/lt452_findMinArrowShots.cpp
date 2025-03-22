#include "lt.h"

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](vector<int> const a, vector<int> const b) { return a[0] < b[0]; });
    int start = 0;
    int numArrow = 0;
    while (start < points.size()) {
      int mergeSize = 0;
      int right = points[start][1];
      for (int j = start + 1; j < points.size(); ++j) {
        if (points[j][0] <= right) {
          right = min(right, points[j][1]);
          mergeSize += 1;
          continue;
        }
        break;
      }
      numArrow += 1;
      start += mergeSize + 1;
    }
    return numArrow;
  }
};

TEST(LeetCodeTest, lt452test) {
  Solution solution;
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  int expected = 2;
  // EXPECT_EQ(solution.findMinArrowShots(points), expected);

  // [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]
  points = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8}};
  expected = 2;
  EXPECT_EQ(solution.findMinArrowShots(points), expected);
}