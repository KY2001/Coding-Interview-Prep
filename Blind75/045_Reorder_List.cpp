#include <bits/stdc++.h>

using namespace std;

// 1 <= |nodes| <= 5 * 10^4
// time: O(|nodes|)
// space: O(|nodes|)
// 13:40
void solve(ListNode* head){
    vector<ListNode*> nodes = {head};
    while(nodes.back()->next){
        nodes.push_back(nodes.back()->next);
    }
    const int n = nodes.size();
    for (int i = 0; i < n; i++){
        if (i == n - 1){
            if (i%2){
                nodes[n - 1 - i/2]->next = NULL;
            }else{
                nodes[i/2]->next = NULL;
            }      
        }else{
            if (i%2){
                nodes[n - 1 - i/2]->next = nodes[(i+1)/2];
            }else{
                nodes[i/2]->next = nodes[n - 1 - (i+1)/2];
            }
        }
    }
}

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
    void reorderList(ListNode* head) {
        return solve(head);
    }
};
