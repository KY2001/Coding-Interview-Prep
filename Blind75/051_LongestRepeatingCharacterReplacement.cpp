#include <bits/stdc++.h>

// n = |s|
// 1 <= n <= 10^5
// for any i, s[i] will be an uppercase English letter
// time: (26 *) O(n)
// space: O(1)
// corner case: ("A", 1), ("AAA", 0)
// 20:00
// 反省：
// l, rよりleft, rightのほうが丁寧
// ansよりmax_lenのほうが良さそう
// alphabetのループはなくてもいける
int solve(const string &s, const int k){
    const int n = s.size();
    const string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int ans = 0;
    for (char alpha: alphabets){
        // [l, r)
        int r = 0;
        int remained_k = k;
        for (int l = 0; l < n; l++){
            for (int i = r; i < n; i++){
                if (s[i] != alpha){
                    if (!remained_k){
                        break;
                    }
                    remained_k--;
                }
                r = i+1;
            }
            if (s[l] != alpha){
                remained_k++;
            }
            ans = max(ans, r - l);
        }
    }
    return ans;
}

class Solution {
public:
    int characterReplacement(string s, int k) {
        return solve(s, k);
    }
};

// s = "AABABBA", k = 1
// alpha = A;
// r = 0, remaind_k = 1;
// l = 0, r = 1;
// 
