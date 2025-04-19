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

class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    inorderTraversal(root);
    index = 0;
  }

  int next() { return values[index++]; }

  bool hasNext() { return index < values.size(); }

 private:
  void inorderTraversal(TreeNode *node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    values.push_back(node->val);
    inorderTraversal(node->right);
  }

  vector<int> values;
  int index;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

TEST(LeetCodeTest, lt173test) {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);
  BSTIterator *iterator = new BSTIterator(root);
  EXPECT_EQ(iterator->next(), 3);    // return 3
  EXPECT_EQ(iterator->next(), 7);    // return 7
  EXPECT_TRUE(iterator->hasNext());  // return true
  EXPECT_EQ(iterator->next(), 9);    // return 9
  EXPECT_TRUE(iterator->hasNext());  // return true
  EXPECT_EQ(iterator->next(), 15);   // return 15
  EXPECT_TRUE(iterator->hasNext());  // return true
  EXPECT_EQ(iterator->next(), 20);   // return 20
  EXPECT_FALSE(iterator->hasNext()); // return false
}
