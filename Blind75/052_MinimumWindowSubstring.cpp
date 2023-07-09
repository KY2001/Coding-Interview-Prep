#include<bits/stdc++.h>
using namespace std;

// string s with length m
// string t with length n
// 1 <= m, n <= 10^5

// 2^n - 1 is the possible number of substring of s
// O(2^n)

// substring of s: a = s[l:r), assume a is the minimum window substring which satisfies the condition.
// all the substring which contains a also satisfy the condition.
// init: variable window x = s[0]
// 1. slid the right index of substring x until the x satisfy the condition.
// 2. slide the left index as much as possible with the satisfied condition.
// 3. inclease the left index by 1
// 4. we memo the current slid as temoporary answer if it is minimum then.
// continue by 1.

// example
// s = "ADOBECODEBANC", t = "ABC"
// x = "A"
// x = "ADOBEC" -> temp answer = "ADOBEC"
// x = "DOBEC" -> x = "DOBECODEBA"
// x = "CODEBA"
// x = "ODEBA"
// x = "ODEBANC" -> x = "BANC"
// temp answer -> "BANC"

bool check(unordered_map<char, int> &characters_in_t, unordered_map<char, int> &characters_in_window){
    for (auto p: characters_in_t){
        if (characters_in_window[p.first] < p.second){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    string minWindow(string &s, string &t) {
        const int n = s.size();
        const int m = t.size();
        unordered_map<char, int> characters_in_t;
        for (char t_char: t){
            characters_in_t[t_char]++;
        }
        deque<char> window;
        unordered_map<char, int> characters_in_window;
        int answer_left = 0, answer_right = 0;
        int left = 0, right = 0;
        while(1){
            while(!check(characters_in_t, characters_in_window)){
                window.emplace_back(s[right]);
                characters_in_window[s[right]]++;
                right++;
                if (right >= n){
                    break;
                }
            }
            if (!check(characters_in_t, characters_in_window)){
                break;
            }
            bool left_slided = false;
            while(characters_in_t[s[left]] <= characters_in_window[s[left]]-1){
                left_slided = true;
                characters_in_window[s[left]]--;
                window.pop_front();
                left++;
            }
            if (answer_right == 0 or answer_right - answer_left > window.size()){
                answer_left = left;
                answer_right = right;
            }
            characters_in_window[s[left]]--;
            window.pop_front();
            left++;
        }
        return s.substr(answer_left, answer_right - answer_left);
    }
};
