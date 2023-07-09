using namespace std;

// O(n * m)
/*
vector<vector<int>> dp;
dp[i][j] = LCS length of text1[:i+1] and text2[:j+1]
= dp[i-1][j-1] + 1 (if text[i] == text[j])
= max(dp[i-1][j], dp[i][j-1]) (else)
・2次元配列は、1次元配列2つに省略できる！！
*/
// 06:06
int solution1(const string &text1, const string &text2){
    const int n = text1.size();
    const int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = (text1[i-1] == text2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]));
        }
    }
    return dp[n][m];
}

class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        return solution1(text1, text2);
    }
};
