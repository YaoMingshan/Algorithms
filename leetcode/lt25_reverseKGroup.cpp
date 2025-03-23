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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* before = dummy;
    ListNode* after = head;
    int count = 0;
    while (after != nullptr) {
      count++;
      after = after->next;
    }
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    // 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7
    // 1 -> 2 -> 3
    // 2 -> 1 -> 3
    // 3 -> 2 -> 1

    ListNode* kHead = dummy;
    ListNode* cur = kHead->next;
    while (count >= k) {
      for (int i = 1; i < k; ++i) {
        ListNode* nxt = cur->next;
        cur->next = nxt->next;
        nxt->next = kHead->next;
        kHead->next = nxt;
      }
      kHead = cur;
      cur = cur->next;
      count -= k;
    }
    return dummy->next;
  }
};

TEST(LeetCodeTest, lt25test) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  Solution s;
  ListNode* result = s.reverseKGroup(head, 2);
  EXPECT_EQ(result->val, 2);
  EXPECT_EQ(result->next->val, 1);
  EXPECT_EQ(result->next->next->val, 4);
  EXPECT_EQ(result->next->next->next->val, 3);
  EXPECT_EQ(result->next->next->next->next->val, 5);
  delete head;
  delete result;
}
