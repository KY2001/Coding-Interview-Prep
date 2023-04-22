#include <bits/stdc++.h>

using namespace std;


// 0 <= k <= 10^4
// 0 <= |lists[i]| <= 500
// -10^4 <= lists[i][j] <= 10^4
// time: O(k * max(|list[i]|) * log(k))
// map.erase(iterator)
// multimap.emplace(key, val)
// 35:38
ListNode* solve(const vector<ListNode*> &lists){
    const int k = lists.size();
    multimap<int, ListNode*> heads;
    for (auto &head: lists){
        if (head) heads.emplace(head->val, head);
    }
    if (heads.empty()) return nullptr;
    ListNode* merged_list = new ListNode();
    ListNode* merged_list_head = begin(heads)->second;
    while(heads.size()){
        const auto min = begin(heads);
        const int min_val = min->first;
        ListNode* min_ListNode = min->second;
        heads.erase(min);
        merged_list->next = min_ListNode;
        merged_list = merged_list->next;
        const auto min_ListNode_next = min_ListNode->next;
        if (min_ListNode_next) heads.emplace(min_ListNode_next->val, min_ListNode_next);
    }
    return merged_list_head;
}

// int main(){

// }

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return solve(lists);
    }
};
