#include "lt.h"

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int sIndex = 0, tIndex = 0;
    while (sIndex < s.size() && tIndex < t.size()) {
      if (s[sIndex] == t[tIndex]) {
        sIndex++;
      }
      tIndex++;
    }
    return sIndex == s.size();
  }
};

TEST(LeetCodeTest, lt392test) {
  Solution solution;
  EXPECT_EQ(solution.isSubsequence("abc", "ahbgdc"), true);
  EXPECT_EQ(solution.isSubsequence("axc", "ahbgdc"), false);
}
