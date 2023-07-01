#include <bits/stdc++.h>

// solution: sliding window

// n = |s|
// time: O(n)
// space: O(n)
// 12:17
int solve(string &s){
    const int n = s.size();
    set<char> s_already_checked;

    int ans = 0;
    // [l, r)
    int r = 0;
    for (int l = 0; l < n; l++){
        for (int i = r; i < n; i++){
            if (!s_already_checked.count(s[i])){
                s_already_checked.insert(s[i]);
            }else{
                break;
            }
            r = i+1;
        }
        s_already_checked.erase(s[l]);
        ans = max(ans, r - l);
    }
    return ans;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return solve(s);
    }
};

// int main(){

// }
