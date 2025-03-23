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
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* lessTail = dummy;
    ListNode* firstGreater = nullptr;
    ListNode* greatTail = nullptr;

    auto h0 = head;

    // 1 -> 3 -> 2 -> 4
    while (h0 != nullptr) {
      if (h0->val < x) {
        lessTail->next = h0;
        h0 = h0->next;
        lessTail = lessTail->next;
        lessTail->next = firstGreater ? firstGreater : h0;
      } else {
        if (firstGreater == nullptr) {
          firstGreater = h0;
          greatTail = h0;
          h0 = h0->next;
          greatTail->next = nullptr;
        } else {
          greatTail->next = h0;
          greatTail = greatTail->next;
          h0 = h0->next;
          greatTail->next = nullptr;
        }
      }
    }

    return dummy->next;
  }
};

TEST(LeetCodeTest, lt86test) {
  Solution s;
  {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode* res = s.partition(head, 3);
    while (res) {
      cout << res->val << " ";
      res = res->next;
    }
  }

  {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    ListNode* res = s.partition(head, 2);
    while (res) {
      cout << res->val << " ";
      res = res->next;
    }
  }
}