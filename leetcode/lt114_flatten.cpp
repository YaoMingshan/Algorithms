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
  void flatten(TreeNode *root) {
    if (!root) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right) root = root->right;
    root->right = tmp;
  }
};

TEST(LeetCodeTest, lt114test) {
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);
  s.flatten(root);
  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->right->val, 2);
  EXPECT_EQ(root->right->right->val, 3);
  EXPECT_EQ(root->right->right->right->val, 4);
  EXPECT_EQ(root->right->right->right->right->val, 5);
  EXPECT_EQ(root->right->right->right->right->right->val, 6);
}