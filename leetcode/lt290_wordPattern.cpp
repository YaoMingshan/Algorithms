#include "lt.h"

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    std::istringstream iss(s);
    std::string word;
    std::unordered_map<char, std::string> charToWord;
    std::unordered_map<std::string, char> wordToChar;
    size_t i = 0;
    while (iss >> word) {
      if (i >= pattern.size()) {
        return false;
      }
      char c = pattern[i];
      if (charToWord.count(c) && charToWord[c] != word) {
        return false;
      }
      if (wordToChar.count(word) && wordToChar[word] != c) {
        return false;
      }
      charToWord[c] = word;
      wordToChar[word] = c;
      ++i;
    }
    return i == pattern.size();
  }
};

TEST(LeetCodeTest, lt290test) {
  Solution s;
  EXPECT_TRUE(s.wordPattern("abba", "dog cat cat dog"));
  EXPECT_FALSE(s.wordPattern("abba", "dog cat cat fish"));
  EXPECT_FALSE(s.wordPattern("aaaa", "dog cat cat dog"));
  EXPECT_FALSE(s.wordPattern("abba", "dog dog dog dog"));
}