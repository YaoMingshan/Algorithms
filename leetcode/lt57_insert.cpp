#include "lt.h"

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    // Sort intervals based on the starting point
    std::sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
    vector<vector<int>> res;
    bool inserted = false;
    for (size_t i = 0; i < intervals.size();) {
      if (intervals[i][1] >= newInterval[0] && !inserted) {
        int j = 0;
        for (j = i; j < intervals.size(); ++j) {
          if (intervals[j][0] > newInterval[1]) {
            break;
          }
        }
        if (j == i) {
          // 无交集
          res.push_back(newInterval);
          res.push_back(intervals[i]);
          i += 1;
        } else {
          int left = std::min(intervals[i][0], newInterval[0]);
          int right = std::max(intervals[j - 1][1], newInterval[1]);
          std::vector<int> merge = {left, right};
          res.push_back(merge);
          i = j;
        }
        inserted = true;
      } else {
        res.push_back(intervals[i]);
        i += 1;
      }
    }

    if (!inserted) res.push_back(newInterval);
    
    return res;
  }
};

TEST(LeetCodeTest, lt57test) {
  Solution solution;
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> newInterval = {2, 5};
  vector<vector<int>> expected = {{1, 5}, {6, 9}};
  EXPECT_EQ(solution.insert(intervals, newInterval), expected);
}