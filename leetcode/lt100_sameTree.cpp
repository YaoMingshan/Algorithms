#include "lt.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if ((p && !q) || (!p && q)) return false;
    bool eq = (p && q && p->val == q->val);
    return eq && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

TEST(LeetCodeTest, lt100test) {
  Solution s;
  TreeNode *p = new TreeNode(1);
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);
  TreeNode *q = new TreeNode(1);
  q->left = new TreeNode(2);
  q->right = new TreeNode(3);
  EXPECT_EQ(s.isSameTree(p, q), true);
}
TEST(LeetCodeTest, lt100test2) {
  Solution s;
  TreeNode *p = new TreeNode(1);
  p->left = new TreeNode(2);
  TreeNode *q = new TreeNode(1);
  q->right = new TreeNode(2);
  EXPECT_EQ(s.isSameTree(p, q), false);
}