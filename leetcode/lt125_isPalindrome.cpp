#include "lt.h"
class Solution {
 public:
  bool isPalindrome(string s) {
    string filtered;
    for (char c : s) {
      if (isalnum(c)) {
        filtered += tolower(c);
      }
    }
    int left = 0, right = filtered.size() - 1;
    while (left < right) {
      if (filtered[left] != filtered[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};

TEST(LeetCodeTest, lt125test) {
  Solution solution;
  EXPECT_TRUE(solution.isPalindrome("A man, a plan, a canal: Panama"));
  EXPECT_FALSE(solution.isPalindrome("race a car"));
  EXPECT_TRUE(solution.isPalindrome(" "));
  EXPECT_TRUE(solution.isPalindrome("No 'x' in Nixon"));
}