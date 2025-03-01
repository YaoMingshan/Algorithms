#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  struct Item {
    int pos;
    int hgh;
  };
  int trap(vector<int>& height) {
    if (height.size() <= 1) return 0;
    std::stack<Item> cols;
    int sum = 0;
    for (int i = 1; i < height.size(); ++i) {
      if (height.at(i - 1) > height.at(i)) {
        cols.push({i - 1, height.at(i - 1)});
      } else if (height.at(i - 1) < height.at(i)) {
        int last_hgh = height.at(i - 1);
        while (!cols.empty()) {
          auto top = cols.top();
          if (top.hgh <= height.at(i)) {
            auto hgh_diff = top.hgh - last_hgh;
            sum += hgh_diff * (i - top.pos - 1);
            last_hgh = top.hgh;
            cols.pop();
            if (top.hgh == height.at(i)) break;
          } else {
            auto hgh_diff = height.at(i) - last_hgh;
            sum += hgh_diff * (i - top.pos - 1);
            break;
          }
        }
      }
    }

    return sum;
  }
};

#include <iostream>

int main() {
  std::vector<int> input = {4,2,0,3,2,5};
  Solution s;
  auto res = s.trap(input);
  std::cout << res << std::endl;
  return 0;
}