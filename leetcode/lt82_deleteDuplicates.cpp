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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    while (curr) {
      if (curr->next && curr->val == curr->next->val) {
        while (curr->next && curr->val == curr->next->val) {
          curr = curr->next;
        }
        prev->next = curr->next;
      } else {
        prev = curr;
      }
      curr = curr->next;
    }
    return dummy->next;  // Return the new head of the list.
  }
};

TEST(LeetCodeTest, lt82test) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  Solution s;
  ListNode* result = s.deleteDuplicates(head);
  EXPECT_EQ(result->val, 1);
  EXPECT_EQ(result->next->val, 2);
  EXPECT_EQ(result->next->next, nullptr);
}