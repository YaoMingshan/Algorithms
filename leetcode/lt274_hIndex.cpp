#include <map>
#include "gtest/gtest.h"

#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    std::map<int, int> refCount;
    for (auto&& i : citations) {
      if (refCount.count(i)) {
        refCount.at(i) += 1;
      } else {
        refCount.insert({i, 1});
      }
    }
    int h = 0;
    int totalPaperNum = citations.size();
    int paperCount = 0;
    for (auto&& it : refCount) {
      auto ref = it.first;
      auto count = it.second;
      int curH = std::min(ref, totalPaperNum - paperCount);
      if (curH > h) {
        h = curH;
      }
      paperCount += count;
    }
    return h;
  }
};

TEST(LeetCodeTest, lt274test) {}
