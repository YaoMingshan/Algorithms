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
  int sumNumbers(TreeNode *root) {
    if (!root) return 0;
    int sum = 0;
    dfs(root, 0, sum);
    return sum;
  }
  void dfs(TreeNode *root, int num, int &sum) {
    if (!root) return;
    num = num * 10 + root->val;
    if (!root->left && !root->right) {
      sum += num;
      return;
    }
    dfs(root->left, num, sum);
    dfs(root->right, num, sum);
  }
};

TEST(LeetCodeTest, lt129test) {
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  EXPECT_EQ(s.sumNumbers(root), 25); // 12 + 13 = 25
  delete root->left;
  delete root->right;
  delete root;
}