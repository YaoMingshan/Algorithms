#include "gtest/gtest.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = m + n - 1;
    while (m > 0 || n > 0) {
      if (m > 0 && n > 0) {
        if (nums1.at(m - 1) >= nums2.at(n - 1)) {
          nums1.at(pos) = nums1.at(m - 1);
          pos--;
          m--;
        } else {
          nums1.at(pos) = nums2.at(n - 1);
          pos--;
          n--;
        }
      } else if (m > 0) {
        nums1.at(pos) = nums1.at(m - 1);
        pos--;
        m--;
      } else {
        nums1.at(pos) = nums2.at(n - 1);
        pos--;
        n--;
      }
    }
  }
};

TEST(LeetCodeTest, lt88test) {}