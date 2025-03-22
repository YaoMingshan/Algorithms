#include "lt.h"

class Solution {
 public:
  int calculate(string s) {
    stack<int> nums;
    stack<char> ops;
    int pos = 0;
    // delete space in string
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    // handle negative number in string
    if (s[0] == '-')
      s.replace(0, 1, "0-");  // replace - to 0- to handle negative
    // replace (- to (0- to handle negative number in bracket
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' && s[i + 1] == '-') {
        s.replace(i + 1, 1, "0-");
        i++;
      }
    }

    while (pos < s.size()) {
      if (s[pos] == ' ') {
        pos++;
        continue;
      }

      if (isdigit(s[pos])) {
        int len = 1;
        while (pos + len < s.size() && isdigit(s[pos + len])) {
          len++;
        }
        int digit = stoi(s.substr(pos, len));
        nums.push(digit);
        pos += len;
        continue;
      }

      if (s[pos] == '(' || s[pos] == '+' || s[pos] == '-') {
        ops.push(s[pos]);
        pos++;
        continue;
      }

      if (s[pos] == ')') {
        int bracket_res = 0;

        while (ops.top() != '(') {
          int val = nums.top();
          char op = ops.top();
          if (op == '+') {
            bracket_res += val;
          } else {
            bracket_res -= val;
          }
          nums.pop();
          ops.pop();
        }

        int val = nums.top();
        bracket_res += val;
        nums.pop();
        ops.pop();

        nums.push(bracket_res);
        pos++;
        continue;
      }
    }

    int result = 0;
    while (!nums.empty()) {
      int val = nums.top();
      nums.pop();
      if (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        if (op == '+') {
          result += val;
        } else {
          result -= val;
        }
      } else {
        result += val;
      }
    }

    return result;
  }
};

TEST(LeetCodeTest, lt224test) {
  Solution solution;
  string s = "(1+(4+5+2)-3)+(6+8)";
  int expected = 23;
  EXPECT_EQ(solution.calculate(s), expected);
  s = "1 + 1";
  expected = 2;
  EXPECT_EQ(solution.calculate(s), expected);
  s = " 2-1 + 2 ";
  expected = 3;
  EXPECT_EQ(solution.calculate(s), expected);
  s = "(1)";
  expected = 1;
  EXPECT_EQ(solution.calculate(s), expected);
}
