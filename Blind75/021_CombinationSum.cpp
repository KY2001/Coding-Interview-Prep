using namespace std;

// O(|nums|^2 * max(nums[i]))
/*
1 <= |nums| <= 200
1 <= nums[i] <= 1000
1 <= sum(comb) <= 4000

dp[i][j] = the number of comibnations such that sum of the elements equals j and combination is consisted of nums[:i+1]
dp[i][j+nums[i]] += dp[i-1][j];
dp[i][j] += dp[i-1][j];
*/
// 08:38
/*
dp[0] = {1, 1, 0, 0, ...}
dp[1] = {1, 1, 1, 1, ...}
dp[2] = {1, 1, 2, 2, 1, 1, ...}
*/
int solution1(const vector<int> &nums, int target){
    const int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n * 1000 + 1));
    dp[0][0] = 1;
    dp[0][nums[0]] = 1;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n * 1000 + 1; j++){
            dp[i+1][j] += dp[i][j];
            if (j + nums[i] > n * 1000) continue;
            dp[i+1][j + nums[i]] += dp[i][j];
        }
    }
    if (target > 1000 * n) return 0;
    return dp[n-1][target];
}

// O(target * |nums|)
/*
dp[i] = number of combination such that sum == i;
*/
// 25:32
int solution2(const vector<int> &nums, int target){
    const int n = nums.size();
    vector<int> dp(target + 1); 
    dp[0] = 1;
    for (int val = 0; val < target; val++){
        for (int num : nums){
            if (val + num > target) continue;
            if (dp[val + num] > INT_MAX - dp[val]) continue;
            dp[val + num] += dp[val];
        }
    }
    return dp[target];
}

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solution2(nums, target);
    }
};
