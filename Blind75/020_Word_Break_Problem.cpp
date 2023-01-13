using namespace std;

// O(|s| * |wordDict| * |word|)
/*
1 <= |s| <= 300
1 <= |wordDict| <= 1000
O(|s| * |wordDict| * |word|) < 6 * 10^6
dp[i] = true if s[:i+1] can be segmented.
dp[i+|word|] = true if s[i:|word|+1] == word
return true if dp[s-1] = true
dp = [0, 0, 0, 0, 0, 1, 0, 0]

std::string::substrの引数を(インデックス, 長さ)ではなく、(L, R)と勘違いしていてバグらせ。
*/
// 14:14

bool solution1(const string &s, const vector<string> &wordDict){
    vector<bool> dp(s.size()+1);
    dp[0] = true;
    for (int i = 0; i < s.size(); i++){
        if (dp[i] == false) continue;
        for (auto &word : wordDict){
            if (s.substr(i, word.size()) == word){
                dp[i + word.size()] = true;
            }
        }
    }
    for (int i = 0; i < dp.size(); i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[s.size()] == true;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return solution1(s, wordDict);
    }
};
