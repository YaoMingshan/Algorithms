#include "lt.h"

class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> stack;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stack.push(c);
      } else {
        if (stack.empty()) return false;
        char top = stack.top();
        stack.pop();
        if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
            (c == '}' && top != '{')) {
          return false;
        }
      }
    }
    return stack.empty();
  }
};

TEST(LeetCodeTest, lt20test) {
  Solution solution;
  string s = "()[]{}";
  bool expected = true;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "(]";
  expected = false;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "([)]";
  expected = false;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "{[]}";
  expected = true;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "(([]){})";
  expected = true;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "(([]){})]";
  expected = false;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "(([]){})[";
  expected = false;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "(([]){})[()]";
  expected = true;
  EXPECT_EQ(solution.isValid(s), expected);
  s = "(([]){})[()])";
  expected = false;
  EXPECT_EQ(solution.isValid(s), expected);
}