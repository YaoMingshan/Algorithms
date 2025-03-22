#include "lt.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
      int x = (l1 != nullptr) ? l1->val : 0;
      int y = (l2 != nullptr) ? l2->val : 0;
      int sum = carry + x + y;
      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
      if (l1 != nullptr) l1 = l1->next;
      if (l2 != nullptr) l2 = l2->next;
    }
    if (carry > 0) {
      current->next = new ListNode(carry);
    }
    return dummyHead->next;
  }
};

TEST(LeetCodeTest, lt2test) {
  Solution solution;
  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  ListNode* expected = new ListNode(7, new ListNode(0, new ListNode(8)));
  ListNode* result = solution.addTwoNumbers(l1, l2);
  while (expected != nullptr && result != nullptr) {
    EXPECT_EQ(expected->val, result->val);
    expected = expected->next;
    result = result->next;
  }
  EXPECT_EQ(expected, nullptr);
  EXPECT_EQ(result, nullptr);
}