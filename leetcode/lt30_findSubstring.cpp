#include "lt.h"

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int ls = s.size();
    int lw = words.at(0).size();
    int wordNum = words.size();
    // 重点是需要多次遍历，次数是单词长度决定，每次按照词长度做匹配，用hash表存储频率
    // string s1 = "barfoothefoobarman" vector<string> words1 = {"foo", "bar"}
    // 需要遍历三次：
    // 1: | bar | foo | the | foo | bar | man |
    // 2: | arf | oot | hef | oob | arm | an
    // 3: | rfo | oth | efo | oba | rma | n

    vector<int> res;
    for (int i = 0; i < lw && i + lw * wordNum <= ls; ++i) {
      std::unordered_map<string, int> count;
      for (int j = i; j < lw * wordNum; j += lw) {
        count[s.substr(j, lw)] += 1;
      }
      for (auto&& word : words) {
        count[word] -= 1;
        if (count[word] == 0) count.erase(word);
      }
      if (count.empty()) res.push_back(i);

      int left = i + lw;
      int right = left + lw * wordNum;
      while (right <= ls) {
        if (--count[s.substr(left - lw, lw)] == 0) {
          count.erase(s.substr(left - lw, lw));
        }
        if (++count[s.substr(right - lw, lw)] == 0) {
          count.erase(s.substr(right - lw, lw));
        }
        if (count.empty()) res.push_back(left);
        left += lw;
        right += lw;
      }
    }
    return res;
  }
};

TEST(LeetCodeTest, lt30test) {
  Solution sol;
  string s1 = "barfoothefoobarman";
  vector<string> words1 = {"foo", "bar"};
  vector<int> expected1 = {0, 9};
  EXPECT_EQ(sol.findSubstring(s1, words1), expected1);
  string s2 = "wordgoodgoodgoodbestword";
  vector<string> words2 = {"word", "good", "best", "word"};
  vector<int> expected2 = {};
  EXPECT_EQ(sol.findSubstring(s2, words2), expected2);
  string s3 = "barfoofoobarthefoobarman";
  vector<string> words3 = {"bar", "foo", "the"};
  vector<int> expected3 = {6, 9, 12};
  EXPECT_EQ(sol.findSubstring(s3, words3), expected3);
  string s4 = "a";
  vector<string> words4 = {"a"};
  vector<int> expected4 = {0};
  EXPECT_EQ(sol.findSubstring(s4, words4), expected4);
}