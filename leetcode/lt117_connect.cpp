#include "lt.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur) {
      Node* dummy = new Node(0);
      Node* pre = dummy;
      while (cur) {
        if (cur->left) {
          pre->next = cur->left;
          pre = pre->next;
        }
        if (cur->right) {
          pre->next = cur->right;
          pre = pre->next;
        }
        cur = cur->next;
      }
      cur = dummy->next;
    }
    return root;
  }
};

TEST(LeetCodeTest, lt117test) {
  Solution s;
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(7);
  s.connect(root);
  EXPECT_EQ(root->left->next, root->right);
  EXPECT_EQ(root->left->left->next, root->left->right);
  EXPECT_EQ(root->left->right->next, root->right->right);
  EXPECT_EQ(root->right->right->next, nullptr);
}