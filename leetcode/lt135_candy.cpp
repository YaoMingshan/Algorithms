#include "gtest/gtest.h"

#include <stack>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
 public:
  int candy(vector<int>& ratings) {
    if (ratings.size() <= 1) return ratings.size();
    std::vector<int> vecCandy(ratings.size(), 0);
    for (int i = 0; i < ratings.size();) {
      if (i == ratings.size() - 1) {
        if (ratings.at(i) > ratings.at(i - 1))
          vecCandy.at(i) = vecCandy.at(i - 1) + 1;
        if (ratings.at(i) <= ratings.at(i - 1)) vecCandy.at(i) = 1;
        break;
      }
      if (ratings.at(i) == ratings.at(i + 1)) {
        int start = i;
        int end = i + 1;
        while (end + 1 < ratings.size() &&
               ratings.at(end + 1) == ratings.at(end)) {
          end++;
        }
        if (start == 0) vecCandy.at(start) = 1;
        for (int j = start; j < end; j++)
          vecCandy.at(j) = std::max(vecCandy.at(j), 1);
        if (end == ratings.size() - 1) {
          vecCandy.at(end) = 1;
          break;
        }
        i = end;
      } else if (ratings.at(i) < ratings.at(i + 1)) {
        int start = i;
        int end = i + 1;
        while (end + 1 < ratings.size() &&
               ratings.at(end) < ratings.at(end + 1)) {
          end++;
        }
        for (int j = start; j <= end; j++) {
          vecCandy.at(j) = std::max(vecCandy.at(j), j - start + 1);
          std::cout << j << ", " << vecCandy.at(j) << std::endl;
        }
        i = end;
      } else {
        int start = i;
        int end = i + 1;
        while (end + 1 < ratings.size() &&
               ratings.at(end) > ratings.at(end + 1)) {
          end++;
        }
        for (int j = end; j >= start; j--) {
          vecCandy.at(j) = std::max(vecCandy.at(j), end - j + 1);
          std::cout << j << ", " << vecCandy.at(j) << std::endl;
        }
        i = end;
      }
    }
    return std::accumulate(vecCandy.begin(), vecCandy.end(), 0);
  }
};

TEST(LeetCodeTest, lt135test) {}
