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
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
  }
  bool isSymmetric(TreeNode *l, TreeNode *r) {
    if (!l && !r) return true;
    if ((!l && r) || (l && !r)) return false;
    return l->val == r->val && isSymmetric(l->left, r->right) &&
           isSymmetric(l->right, r->left);
  }
};

TEST(LeetCodeTest, lt101test) {
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);
  EXPECT_TRUE(s.isSymmetric(root));
}