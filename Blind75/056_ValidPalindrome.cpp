#include<bits/stdc++.h>

using namespace std;


const string LOWRES = "abcdefghijklmnopqrstuvwxyz";
const string UPPERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string NUMBERS = "0123456789";

// Time: O(n) where n == |s|
// Space: O(n)
// 16:00 <- took too much time

bool IsAlphanumericCharacter(const char ch) {
  return ('a' <= ch and ch <= 'z') or ('0' <= ch and ch <= '9');
}

bool solve(string &s) {
  const int n = s.size();

  for (char &ch: s) {
    if ('A' <= ch and ch <= 'Z') {
      ch = ch - ('A' - 'a');
    }
  }

  int left = 0;
  int right = n - 1;
  while(right > left) {
    while(!IsAlphanumericCharacter(s[left])){
      if (left > n - 1) {
        return true;
      }
      left++;
    }
    while(!IsAlphanumericCharacter(s[right])){
      if (right < 0) {
        return true;
      }
      right--;
    }
    if (right < left) {
      return true;
    }
    if (s[left] != s[right]) {
      return false;
    }
    left++;
    right--;
  }

  return true;
}

class Solution {
public:
    bool isPalindrome(string &s) {
      return solve(s);
    }
};
