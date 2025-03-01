#include "gtest/gtest.h"

#include <stack>
#include <vector>

using namespace std;
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.size() <= 1) return true;
    int pos = 0;
    bool reach = false;
    while (pos != nums.size() - 1) {
      int steps = nums.at(pos);
      if (nums.size() - 1 - pos <= steps) {
        return true;
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
        if (!hasPath) return false;
        pos = nextPos;
      }
    }
    return true;
  }
};

TEST(LeetCodeTest, lt55test) {}
