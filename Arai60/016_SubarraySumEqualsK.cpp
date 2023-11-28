#include<bits/stdc++.h>

using namespace std;


// n = |nums|
// 1 <= n <= 2 * 10^4
// -1000 <= nums[i] <= 1000
// -10^7 <= k <= 10^7

// Time: O(nlogn)
// Space: O(n)
// 18:30

int solve(vector<int> &nums, const int k) {
  const int n = nums.size();
  for (int i = 0; i < n-1; i++) {
    nums[i+1] += nums[i];
  }

  unordered_map<int, vector<int>> count_cumsum;
  for (int i = 0; i < n; i++) {
    count_cumsum[nums[i]].push_back(i);
  }

  // a <= b, [a, b]
  // cumsum[b] - cumsum[a-1] == k -> sum is k

  int answer = 0;
  for (int i = 0; i < n; i++) {
    int cum_sum = 0;
    if (i != 0) {
      cum_sum = nums[i-1];
    }

    // cum_sum[x] == k + cum_sum and x >= i
    const vector<int> &indices = count_cumsum[k + cum_sum];
    const auto lb = lower_bound(begin(indices), end(indices), i);
    if (lb != end(indices)) {
      answer += indices.size() - (lb - begin(indices));
    }
  }

  return answer;
}

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};
