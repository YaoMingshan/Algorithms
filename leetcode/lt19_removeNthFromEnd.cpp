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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    for (int i = 0; i <= n; i++) {
      first = first->next;
    }
    while (first != nullptr) {
      first = first->next;
      second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;
  }
};

TEST(LeetCodeTest, lt19test) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  Solution s;
  ListNode* result = s.removeNthFromEnd(head, 2);
  EXPECT_EQ(result->val, 1);
  EXPECT_EQ(result->next->val, 2);
  EXPECT_EQ(result->next->next->val, 3);
  EXPECT_EQ(result->next->next->next->val, 5);
}