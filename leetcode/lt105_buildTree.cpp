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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty()) {
      return nullptr;
    }
    int rootVal = preorder[0];
    TreeNode *root = new TreeNode(rootVal);
    auto it = find(inorder.begin(), inorder.end(), rootVal);
    int leftSize = it - inorder.begin();
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
    vector<int> leftInorder(inorder.begin(), it);
    vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
    vector<int> rightInorder(it + 1, inorder.end());
    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);
    return root;
  }
};

TEST(LeetCodeTest, lt105test) {
  Solution s;
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  TreeNode *root = s.buildTree(preorder, inorder);
  // Add assertions to verify the correctness of the constructed tree.
  EXPECT_EQ(root->val, 3);
  EXPECT_EQ(root->left->val, 9);
  EXPECT_EQ(root->right->val, 20);
  EXPECT_EQ(root->right->left->val, 15);
  EXPECT_EQ(root->right->right->val, 7);
}