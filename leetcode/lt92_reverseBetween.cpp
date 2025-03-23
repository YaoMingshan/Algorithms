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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for (int i = 0; i < left - 1; i++) {
      prev = prev->next;
    }
    ListNode* start = prev->next;
    ListNode* then = start->next;
    for (int i = 0; i < right - left; i++) {
      start->next = then->next;
      then->next = prev->next;
      prev->next = then;
      then = start->next;
    }
    return dummy->next;
  }
};

TEST(LeetCodeTest, lt92test) {
  Solution s;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  ListNode* result = s.reverseBetween(head, 2, 4);
  EXPECT_EQ(result->val, 1);
  EXPECT_EQ(result->next->val, 4);
  EXPECT_EQ(result->next->next->val, 3);
  EXPECT_EQ(result->next->next->next->val, 2);
  EXPECT_EQ(result->next->next->next->next->val, 5);
}