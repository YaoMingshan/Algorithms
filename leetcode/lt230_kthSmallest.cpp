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
  int kthSmallest(TreeNode *root, int k) {
    int res = 0;
    int cnt = 0;
    inorder(root, k, cnt, res);
    return res;
  }
  void inorder(TreeNode *root, int k, int &cnt, int &res) {
    if (!root) return;
    inorder(root->left, k, cnt, res);
    cnt++;
    if (cnt == k) {
      res = root->val;
      return;
    }
    inorder(root->right, k, cnt, res);
  }
};

TEST(LeetCodeTest, lt230test) {
  Solution s;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->right = new TreeNode(2);
  EXPECT_EQ(s.kthSmallest(root, 1), 1);
}