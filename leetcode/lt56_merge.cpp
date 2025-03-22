#include "lt.h"

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;
    std::sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    vector<vector<int>> res;
    res.push_back(intervals[0]);
    int right = intervals[0][1];
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= right && intervals[i][1] > right) {
        res[res.size() - 1][1] = intervals[i][1];
        right = intervals[i][1];
      } else if (intervals[i][0] > right) {
        res.push_back(intervals[i]);
        right = intervals[i][1];
      }
    }

    return res;
  }
};

TEST(LeetCodeTest, lt56test) {
  Solution solution;
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
  EXPECT_EQ(solution.merge(intervals), expected);
}