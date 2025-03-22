#include "lt.h"

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<char, int> char_count;
    for (const auto& ch : magazine) {
      char_count[ch]++;
    }
    for (const auto& ch : ransomNote) {
      if (char_count.find(ch) == char_count.end() || char_count[ch] == 0) {
        return false;
      }
      char_count[ch]--;
    }
    return true;
  }
};

TEST(LeetCodeTest, lt383test) {
  Solution solution;
  EXPECT_EQ(solution.canConstruct("a", "b"), false);
  EXPECT_EQ(solution.canConstruct("aa", "ab"), false);
  EXPECT_EQ(solution.canConstruct("aa", "aab"), true);
}