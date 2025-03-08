#include "lt.h"

class Solution {
 public:
  string reverseWords(string s) {
    std::string res = "";
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == ' ') {
        continue;
      }
      int j = i;
      while (j >= 0 && s[j] != ' ') {
        j--;
      }
      res += s.substr(j + 1, i - j) + " ";
      i = j;
    }
    if (!res.empty()) {
      res.pop_back();
    }
    return res;
  }
};

TEST(LeetCodeTest, lt151test) {
  Solution sol;
  EXPECT_EQ(sol.reverseWords("the sky is blue"), "blue is sky the");
  EXPECT_EQ(sol.reverseWords("  hello world!  "), "world! hello");
}