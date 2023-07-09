using namespace std;

/*
dp[i] = the number of ways to cliimb to the i-th step(段差).
*/

// O(n)
// 04:50
int solution1(int n){
    if (n == 1) return 1;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp.back(); // std::vector::backは末尾要素への"参照"を返す。
}

class Solution {
public:
    int climbStairs(int n) {
        return solution1(n);
    }
};
