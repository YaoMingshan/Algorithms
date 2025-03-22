#include "lt.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head || !head->next) {
      return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
      if (!fast || !fast->next) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return true;
  }
};

TEST(LeetCodeTest, lt141test) {
  Solution solution;
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  EXPECT_TRUE(solution.hasCycle(head));
  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = head2;
  EXPECT_TRUE(solution.hasCycle(head2));
  ListNode *head3 = new ListNode(1);
  EXPECT_FALSE(solution.hasCycle(head3));
}