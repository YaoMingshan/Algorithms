#include "gtest/gtest.h"

#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;
    int start = 0;
    for (int end = nums.size() - 1; start < end;) {
      if (nums.at(start) == val) {
        if (nums.at(end) != val) {
          nums.at(start) = nums.at(end);
          nums.at(end) = val;
          end--;
          start++;
        } else {
          end--;
        }
      } else {
        start++;
      }
    }
    if (nums.at(start) == val)
      return start;
    else
      return start + 1;
  }
};

TEST(LeetCodeTest, lt21test) {}
