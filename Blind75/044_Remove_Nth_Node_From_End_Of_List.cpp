#include <bits/stdc++.h>

using namespace std;

int get_length(ListNode* head){
    int length = 1;
    while(head->next){
        head = head->next;
        length++;
    }
    return length;
}

// 1 <= length <= 30
// 1 <= n <= length
// time: O(length)
// space: O(length)
// 10:54
// https://jamboard.google.com/d/1OZEl_blyHIrrsj7_m7PLFGTJ4nhQ5A42c4TCLSmAPHk/edit?usp=sharing
ListNode* solve(ListNode* head, const int n){
    const int n_from_first = get_length(head) - n + 1;
    if (n_from_first == 1 and !head->next){
        return NULL;
    }else if (n_from_first == 1){
        return head->next;
    }else{ // n_from_first >= 2
        ListNode* prev = head;
        ListNode* current = head->next;
        int count = 2;
        while(count != n_from_first){
            prev = current;
            current = current->next;
            count++;
        }
        if (!current->next){
            prev->next = NULL;
        }else{
            prev->next = current->next;
        }
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return solve(head, n);
    }
};
