using namespace std;

/*
dp[i] = number of decoding patterns of s[:i+1]
dp[i+1] += dp[i] if 1 <= s[i+1] <= 26
dp[i+2] += dp[i] if 1 <= s[i+1:i+3] <= 26
*/
// O(|s|)
// 10:44
bool decodable(int a){
    return 1 <= a and a <= 26;
}

int solution1(const string &s){
    const int n = s.size();
    vector<int> dp(n);
    if (decodable(s[0] - '0')){
        dp[0] += 1;
    }
    if (s.size() == 1) return dp[0];
    if (decodable(stoi(s.substr(0, 2))) and s[0] != '0'){
        dp[1] += 1;
    }
    for (int i = 0; i < n-1; i++){
        if (decodable(s[i+1] - '0')){
            dp[i+1] += dp[i];
        }
        if (i+2 >= n) continue;
        if (decodable(stoi(s.substr(i+1, 2))) and s[i+1] != '0'){
            dp[i+2] += dp[i];
        }
    }
    return dp[n-1];
}

class Solution {
public:
    int numDecodings(string s) {
        return solution1(s);
    }
};
