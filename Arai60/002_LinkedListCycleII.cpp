#include<bits/stdc++.h>

using namespace std;

// Time: O(n), where n is the number of nodes until finding the cycle
// Space: O(n), where n is the number of nodes until finding the cycle
// 13:00

ListNode* findBeginningOfCycle(ListNode *head) {
  if (!head) {
    return nullptr;
  }

  auto temp = addressof(head);
  cout << temp << endl;

  unordered_set<ListNode*> nodes;
  nodes.insert(head);
  ListNode* current_node = head;
  while(current_node->next) {
    const auto next_node = current_node->next;
    if (nodes.count(next_node)) {
      return next_node;
    }
    nodes.insert(next_node);
    current_node = next_node;
  }

  return nullptr;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return findBeginningOfCycle(head);
    }
};
