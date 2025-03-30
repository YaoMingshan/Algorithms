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
 private:
  int maxSum = INT_MIN;

 public:
  int maxGain(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    // 递归计算左右子节点的最大贡献值
    // 只有在最大贡献值大于 0 时，才会选取对应子节点
    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
    int priceNewpath = node->val + leftGain + rightGain;

    // 更新答案
    maxSum = max(maxSum, priceNewpath);

    // 返回节点的最大贡献值
    return node->val + max(leftGain, rightGain);
  }

  int maxPathSum(TreeNode *root) {
    maxGain(root);
    return maxSum;
  }
};

TEST(LeetCodeTest, lt124test) {
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  EXPECT_EQ(s.maxPathSum(root), 6);
  delete root->left;
  delete root->right;
  delete root;
}
TEST(LeetCodeTest, lt124test2) {
  Solution s;
  TreeNode *root = new TreeNode(-10);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  EXPECT_EQ(s.maxPathSum(root), 42);
  delete root->left;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;
}
