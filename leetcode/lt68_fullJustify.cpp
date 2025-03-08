#include "lt.h"

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int i = 0;
    while (i < n) {
      int j = i + 1;
      int lineLength = words[i].length();
      while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
        lineLength += words[j].length();
        j++;
      }
      int numWords = j - i;
      int numSpaces = maxWidth - lineLength;
      if (numWords == 1 || j == n) {
        // Left justify
        string line = words[i];
        for (int k = i + 1; k < j; k++) {
          line += " " + words[k];
        }
        line += string(maxWidth - line.length(), ' ');
        result.push_back(line);
      } else {
        // Full justify
        int spacesBetweenWords = numSpaces / (numWords - 1);
        int extraSpaces = numSpaces % (numWords - 1);
        string line = words[i];
        for (int k = i + 1; k < j; k++) {
          line += string(spacesBetweenWords + (extraSpaces-- > 0 ? 1 : 0), ' ') + words[k];
        }
        result.push_back(line);
      }
      i = j;
    }
    return result;
  }
};

TEST(LeetCodeTest, lt68test) {
  Solution s;
  vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;
  vector<string> expected = {"This    is    an", "example  of text", "justification.  "};
  vector<string> result = s.fullJustify(words, maxWidth);
  EXPECT_EQ(result, expected);
}