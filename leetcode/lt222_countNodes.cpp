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
  /*
   * 完全二叉树 ： 从上到下，从左到右排列一棵树
   * 所以，左子树高度最多比右子树高度多1，或者相等
   * 不可能出现右子树比左子树高的情况
   */
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int leftHeight = getHeight(root->left);    // 左子树高度
    int rightHeight = getHeight(root->right);  // 右子树高度
    if (leftHeight == rightHeight) {
      // 左子树高度 = 右子树高度，则左子树必定是满二叉树
      return (1 << leftHeight) + countNodes(root->right);
    } else {
      // 左子树高度 > 右子树高度，说明右子树必定是满二叉树
      return (1 << rightHeight) + countNodes(root->left);
    }
  }

  int getHeight(TreeNode* root) {
    // 计算左路径的高度，因为是完全二叉树，不需要考虑右边
    int height = 0;
    while (root != nullptr) {
      height++;
      root = root->left;
    }
    return height;
  }
};

TEST(LeetCodeTest, lt222test) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  Solution solution;
  EXPECT_EQ(solution.countNodes(root), 6);
}