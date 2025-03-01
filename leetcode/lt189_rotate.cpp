#include <algorithm>
#include "gtest/gtest.h"

#include <stack>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (nums.size() <= 1) return;
    if (k >= nums.size()) k = k % nums.size();
    if (k == 0) return;
    int cycles = std::gcd(nums.size(), k);
    for (int i = 0; i < cycles; ++i) {
      int val = nums.at(i);
      int current = i;
      do {
        int next = (current + k) % nums.size();
        int tmp = nums.at(next);
        nums.at(next) = val;
        val = tmp;
        current = next;
      } while (current != i);
    }
  }
};

TEST(LeetCodeTest, lt189test) {}
