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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = q.front();
        q.pop();
        if (i == size - 1) ans.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return ans;
  }
};

TEST(LeetCodeTest, lt199test) {
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  vector<int> ans = s.rightSideView(root);
  vector<int> expected = {1, 3, 4};
  EXPECT_EQ(ans, expected);
  delete root; // Clean up memory
}