using namespace std;

/*
1 < |coins| < 12
0 <= amount <= 10^4
dp[i] = minimum number of required coins to make money i.
dp[i] = min_j (dp[i - coins[j]]) + 1
O(|coins| * amount)
denominationは通貨単位の意味。
*/

// O(|coins| * amount)
// 06:55
// 計算量が悪くても、ちゃんと思いついた解法はすべて説明する！！
// 
int solution1(const vector<int> &coins, const int amount){
    const int INF = 100000;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++){
        for (int denomination: coins){
            if (i - denomination < 0) continue;
            dp[i] = min(dp[i], dp[i - denomination] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return solution1(coins, amount);
    }
};
