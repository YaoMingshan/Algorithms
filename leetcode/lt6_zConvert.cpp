#include "lt.h"

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string res = "";
    int n = s.size();
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < n; j++) {
        if (j % (2 * numRows - 2) == i ||
            j % (2 * numRows - 2) == 2 * numRows - 2 - i) {
          res += s[j];
        }
      }
    }
    return res;
  }
};

TEST(LeetCodeTest, lt6test) {
  Solution sol;
  EXPECT_EQ(sol.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
  EXPECT_EQ(sol.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}