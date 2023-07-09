#include<bits/stdc++.h>

using namespace std;

// 0 <= |list1|, |list2| <= 50
// time: O(max(|list1|, |list2|))
// space: O(1)
// 18:17
// https://jamboard.google.com/d/1AYW4f7FlhK6PvVwCOR0m2__3Opwy3RVKZgd0zqWGgSA/edit?usp=sharing
ListNode* solve(ListNode* list1, ListNode* list2){
    if (!list1) return list2;
    if (!list2) return list1;
    ListNode* head;
    if (list1->val <= list2->val){
        head = list1;
        list1 = list1->next;
    }else{
        head = list2;
        list2 = list2->next;
    }
    ListNode* back = head;
    while(list1 and list2){
        if (list1->val <= list2->val){
            back->next = list1;
            list1 = list1->next;
        }else{
            back->next = list2;
            list2 = list2->next;
        }
        back = back->next;
    }
    if (list1){
        back->next = list1;
    }else{
        back->next = list2;
    }
    return head;
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return solve(list1, list2);
    }
};
