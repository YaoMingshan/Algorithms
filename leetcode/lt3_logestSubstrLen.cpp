#include "lt.h"

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0, start = 0;
    for (int end = 0; end < s.size(); ++end) {
      if (charIndexMap.find(s[end]) != charIndexMap.end()) {
        start = max(start, charIndexMap[s[end]] + 1);
      }
      charIndexMap[s[end]] = end;
      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};

TEST(LeetCodeTest, lt3test) {
  Solution sol;
  string s1 = "abcabcbb";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s1), 3);
  string s2 = "bbbbb";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s2), 1);
  string s3 = "pwwkew";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s3), 3);
}