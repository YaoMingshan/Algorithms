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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) return head;
    ListNode* fast = head;
    ListNode* slow = head;
    int len = 1;
    while (fast->next != nullptr) {
      fast = fast->next;
      len++;
    }
    fast->next = head;
    k = k % len;
    for (int i = 1; i < len - k; i++) {
      slow = slow->next;
    }
    head = slow->next;
    slow->next = nullptr;
    return head;
  }
};

TEST(LeetCodeTest, lt61test) {
  Solution s;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  ListNode* res = s.rotateRight(head, 2);
  ListNode* expected = new ListNode(4);
  expected->next = new ListNode(5);
  expected->next->next = new ListNode(1);
  expected->next->next->next = new ListNode(2);
  expected->next->next->next->next = new ListNode(3);
  while (res != nullptr && expected != nullptr) {
    EXPECT_EQ(res->val, expected->val);
    res = res->next;
    expected = expected->next;
  }
  EXPECT_EQ(res, expected);  // Both should be nullptr if equal lists
}