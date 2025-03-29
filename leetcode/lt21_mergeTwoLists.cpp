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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        current->next = list1;
        list1 = list1->next;
      } else {
        current->next = list2;
        list2 = list2->next;
      }
      current = current->next;
    }
    if (list1 != nullptr) {
      current->next = list1;
    } else {
      current->next = list2;
    }
    return dummy->next;
  }
};

TEST(LeetCodeTest, lt21test) {
  Solution solution;
  ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  ListNode* expected = new ListNode(
      1, new ListNode(1, new ListNode(2, new ListNode(3,
                                                      new ListNode(4, new ListNode(4))))));
  ListNode* result = solution.mergeTwoLists(list1, list2);
  while (expected != nullptr && result != nullptr) {
    EXPECT_EQ(expected->val, result->val);
    expected = expected->next;
    result = result->next;
  }  
}