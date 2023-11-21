#include<bits/stdc++.h>

using namespace std;

// Time: O(|s|)
// Space: O(|s|)
// 15:24

bool solve(const string &s) {
  vector<char> stack;
  for (const char ch: s) {
    if (ch == '(' or ch == '{' or ch == '[') {
      stack.push_back(ch);
    } else if (ch == ')' or ch == '}' or ch == ']') {
      if (stack.empty()) {
        return false;
      }
      const char back = stack.back();
      stack.pop_back();
      if ((back == '(' and ch != ')') or (back == '{' and ch != '}') or (back == '[' and ch != ']')) {
        return false;
      }
    }
  }
  if (stack.empty()) {
    return true;
  }
  return false;
}

class Solution {
public:
    bool isValid(const string &s) {
        return solve(s);
    }
};
