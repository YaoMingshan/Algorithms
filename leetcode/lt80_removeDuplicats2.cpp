#include <stack>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int left = 1;
        int right = 2;
        for (; right < nums.size(); ++right) {
            if (nums.at(left) == nums.at(left - 1)
                && nums.at(right) == nums.at(left)) {
                continue;
            } else {
                left++;
                nums.at(left) = nums.at(right);
            }
        }
        return left + 1;
    }
};

TEST(LeetCodeTest, lt80test) {}
