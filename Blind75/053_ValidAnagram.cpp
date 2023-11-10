#include <bits/stdc++.h>

using namespace std;

// ex.
// anagram -> nagaram

// 1 <= |s|, |t| <= 5 * 10^4
// letters are lower english leters. -> 26

// Time: O(max(|s|, |t|))
// Space: O(max(|s|, |t|))
// 7:38

const int NumOfLetters = 26;

vector<int> numberofLetters(const string &a) {
  vector<int> ret(NumOfLetters);
  for (const char ch: a) {
    ret[ch-'a']++;
  }
  return ret;
}

int isAnagram(string &s, string &t) {
  if (numberofLetters(s) == numberofLetters(t)) {
    return true;
  }
  return false;
}

class Solution {
public:
    bool isAnagram(string &s, string &t) {
        if (numberofLetters(s) == numberofLetters(t)) {
            return true;
        }
        return false;
    }
};
