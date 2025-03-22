#include "lt.h"

class Solution {
 public:
  string simplifyPath(string path) {
    std::stack<string> stack;
    std::stringstream ss(path);
    string token;
    while (std::getline(ss, token, '/')) {
      if (token == "" || token == ".") {
        continue;
      }
      if (token == "..") {
        if (!stack.empty()) {
          stack.pop();
        }
      } else {
        stack.push(token);
      }
    }
    string result = "";
    while (!stack.empty()) {
      result = "/" + stack.top() + result;
      stack.pop();
    }
    return result.empty() ? "/" : result;
  }
};

TEST(LeetCodeTest, lt71test) {
  Solution solution;
  string path = "/home/";
  string expected = "/home";
  EXPECT_EQ(solution.simplifyPath(path), expected);
  path = "/../";
  expected = "/";
  EXPECT_EQ(solution.simplifyPath(path), expected);
  path = "/home//foo/";
  expected = "/home/foo";
  EXPECT_EQ(solution.simplifyPath(path), expected);
  path = "/a/./b/../../c/";
  expected = "/c";
  EXPECT_EQ(solution.simplifyPath(path), expected);
}