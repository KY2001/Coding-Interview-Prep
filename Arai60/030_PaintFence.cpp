#include<bits/stdc++.h>

using namespace std;

// a_1, a_2, a_3, a_4, a_5, ... a_n
// 1 <= n <= 50
// 1 <= k <= 10^5

// vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2)));
// dp[a][b][c] -> the number of ways of 1 to (a+1)th post where (a+1)th post's color is b and it continues c times. 

// dp[a][b][0] = sum of (dp[a-1][i][0] + dp[a-1][i][1]) for i != b
// dp[a][b][1] = dp[a-1][b][0]

// answer -> sum of (dp[n-1][i][0] + dp[n-1][i][1]) for every i


// Time: O(n * k)
// Space: O(n * k)
// 14:15

int solve(const int n, const int k) {
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2)));

  for (int i = 0; i < k; i++) {
    dp[0][i][0] = 1;
  }

  int sum = k;
  for (int i = 1; i < n; i++) {
    int next_sum = 0;
    for (int j = 0; j < k; j++) {
      dp[i][j][0] = sum - (dp[i-1][j][0] + dp[i-1][j][1]);
      dp[i][j][1] = dp[i-1][j][0];
      next_sum += dp[i][j][0] + dp[i][j][1];
    }
    sum = next_sum;
  }

  return sum;
}

class Solution {
public:
    int numWays(int n, int k) {
        return solve(n, k);
    }
};
