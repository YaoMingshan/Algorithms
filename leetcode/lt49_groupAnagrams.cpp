#include "lt.h"

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagrams;
    for (auto&& str : strs) {
      auto sortedStr = str;
      std::sort(sortedStr.begin(), sortedStr.end());
      anagrams[sortedStr].push_back(str);
    }
    std::vector<std::vector<std::string>> result;
    for (auto&& it : anagrams) {
      result.push_back(it.second);
    }
    return result;
  }
};

TEST(LeetCodeTest, lt49test) {
  Solution s;
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto result = s.groupAnagrams(strs);
  for (auto&& group : result) {
    for (auto&& str : group) {
      std::cout << str << " ";
    }
    std::cout << std::endl;
  }
}