#include "lt.h"

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::unordered_map<char, char> s_to_t;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s_to_t.find(s[i]) == s_to_t.end()) {
        s_to_t[s[i]] = t[i];
      } else if (s_to_t[s[i]] != t[i]) {
        return false;
      }
    }
    std::unordered_map<char, char> t_to_s;
    for (size_t i = 0; i < t.size(); ++i) {
      if (t_to_s.find(t[i]) == t_to_s.end()) {
        t_to_s[t[i]] = s[i];
      } else if (t_to_s[t[i]] != s[i]) {
        return false;
      }
    }
    return true;
  }
};

TEST(LeetCodeTest, lt205test) {
  Solution s;
  EXPECT_EQ(s.isIsomorphic("egg", "add"), true);
  EXPECT_EQ(s.isIsomorphic("foo", "bar"), false);
  EXPECT_EQ(s.isIsomorphic("paper", "title"), true);
  EXPECT_EQ(s.isIsomorphic("badc", "baba"), false);
}