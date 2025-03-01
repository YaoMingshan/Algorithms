#include "gtest/gtest.h"

#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    int pos = 0;
    int jumpNum = 0;
    while (pos != nums.size() - 1) {
      int steps = nums.at(pos);
      if (nums.size() - 1 - pos <= steps) {
        jumpNum++;
        break;
      } else {
        bool hasPath = false;
        int maxJump = 0;
        int nextPos = pos;
        for (int j = steps; j >= 1; j--) {
          int jump = j + nums.at(pos + j);
          if (nums.at(pos + j) != 0) {
            hasPath = true;
            if (jump > maxJump) {
              maxJump = jump;
              nextPos = pos + j;
            }
          }
        }
        pos = nextPos;
        jumpNum++;
      }
    }
    return jumpNum;
  }
};

TEST(LeetCodeTest, lt45test) {}
