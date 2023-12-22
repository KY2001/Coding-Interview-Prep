#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

// 07:20
// Time: O(nlogn) 
// Space: O(n)

int solve(const vector<int> &nums) {
  const int n = nums.size();

  vector<int> dp(n, INF);
  for (const int num: nums) {
    const auto iter = lower_bound(begin(dp), end(dp), num);
    const int index = iter - begin(dp);

    dp[index] = num;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (dp[i] != INF) {
      return i+1;
    }
  }

  return -1;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums);
    }
};
