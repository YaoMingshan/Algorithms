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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty() || postorder.empty()) return nullptr;
    int rootVal = postorder.back();
    TreeNode *root = new TreeNode(rootVal);
    int rootIndex = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
    vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
    vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootIndex);
    vector<int> rightPostorder(postorder.begin() + rootIndex, postorder.end() - 1);
    root->left = buildTree(leftInorder, leftPostorder);
    root->right = buildTree(rightInorder, rightPostorder);
    return root;
  }
};

TEST(LeetCodeTest, lt106test) {
  Solution s;
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};
  TreeNode *root = s.buildTree(inorder, postorder);
  EXPECT_EQ(root->val, 3);
  EXPECT_EQ(root->left->val, 9);
  EXPECT_EQ(root->right->val, 20);
  EXPECT_EQ(root->right->left->val, 15);
  EXPECT_EQ(root->right->right->val, 7);
}