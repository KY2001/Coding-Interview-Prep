#include<bits/stdc++.h>

using namespace std;


// M = sum_i |s_i|
// Time: O(MlogM)
// Space: O(M)
// 08:40

// |s|
map<char, int> get_characters_count(const string &s) {
  map<char, int> ret;
  for (const char ch: s) {
    ret[ch]++;
  }
  return ret;
}

vector<vector<string>> solve(const vector<string> &strs) {
  map<map<char, int>, vector<string>> anagram_groups;
  // sum_i |s_i|
  // ここポインターにしたらもっとはやくなる
  for (const string &s: strs) {
    anagram_groups[get_characters_count(s)].push_back(s);
  }

  vector<vector<string>> answer;
  for (const auto &anagram_groups_element: anagram_groups) {
    answer.push_back(anagram_groups_element.second);
  }

  return answer;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return solve(strs);
    }
};
