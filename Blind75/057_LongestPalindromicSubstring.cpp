#include <bits/stdc++.h>

using namespace std;

// Time: O(|s|^2)
// Space: O(|s|^2)
// 16:45

string solve(const string &s) {
  const int n = s.size();

  if (n == 0) {
    return "";
  }

  vector<vector<bool>> dp(n, vector<bool>(n));
  // dp[left][right] = true if s[left:right] is palindrome.
  // dp[left][right] = true if dp[left+1][right-1] = true and s[left] == s[right]

  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
  }

  int left_longest = 0;
  int length_longest = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i+1]) {
      dp[i][i+1] = true;
      left_longest = i;
      length_longest = 2;
    }
  }

  for (int length = 3; length <= n; length++) {
    for (int left = 0; left + length - 1 < n; left++) {
      const int right = left + length - 1;
      if (dp[left+1][right-1] and s[left] == s[right]) {
        dp[left][right] = true;
        if (length > length_longest) {
          left_longest = left;
          length_longest = length;
        }
      }
    }
  }

  return s.substr(left_longest, length_longest);
}

class Solution {
public:
    string longestPalindrome(string &s) {
        return solve(s);
    }
};
