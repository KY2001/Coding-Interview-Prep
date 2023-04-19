/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 0 <= |length| <= 10^4
// -10^5 <= node.val <= 10^5
// node.val is unique

// time: O(n)
// space: O(n)
// not set<*ListNode> but set<ListNode*>
// 18:20
bool solve(ListNode * head) {
  if (head == NULL) return false;
  unordered_set < ListNode * > memory;
  ListNode * current = head;
  while (current -> next) {
    if (memory.count(current)) {
      return true;
    } else {
      memory.insert(current);
    }
    current = current -> next;
  }
  return false;
}

// time: O(n)
// space: O(1)
// Floyd's Cycle Finding Algorithm
// 28:13
bool solve2(ListNode * head) {
  if (head == NULL) return false;
  ListNode * fast = head;
  ListNode * slow = head;
  while (true) {
    if (!(fast -> next)) break;
    fast = fast -> next;
    if (!(fast -> next)) break;
    fast = fast -> next;
    slow = slow -> next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

class Solution {
  public: bool hasCycle(ListNode * head) {
    return solve2(head);
  }
};
