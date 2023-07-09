#include <bits/stdc++.h>

using namespace std;

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

// 

// time: O(N)
// space: O(1)
// 39:29
class Solution {
  public: ListNode * reverseList(ListNode * head) {
    if (!head or!head -> next) return head;
    ListNode * prev = head;
    ListNode * current = head -> next;
    ListNode * next;
    while (1) {
      if (current -> next) {
        next = current -> next;
      } else {
        next = NULL;
      }
      current -> next = prev;
      if (!next) break;
      prev = current;
      current = next;
    }
    head -> next = NULL;
    return current;
  }
};
