#include "lt.h"

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    for (const string& token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        if (token == "+") {
          stack.push(a + b);
        } else if (token == "-") {
          stack.push(a - b);
        } else if (token == "*") {
          stack.push(a * b);
        } else if (token == "/") {
          stack.push(a / b);
        }
      } else {
        stack.push(stoi(token));
      }
    }
    return stack.top();
  }
};

TEST(LeetCodeTest, lt150test) {
  Solution solution;
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  int expected = 9;
  EXPECT_EQ(solution.evalRPN(tokens), expected);

  tokens = {"4", "13", "5", "/", "+"};
  expected = 6;
  EXPECT_EQ(solution.evalRPN(tokens), expected);

  tokens = {"10", "6", "9",  "3", "+", "-11", "*",
            "/",  "*", "17", "+", "5", "+"};
  expected = 22;
  EXPECT_EQ(solution.evalRPN(tokens), expected);
}