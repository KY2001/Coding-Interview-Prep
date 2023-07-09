using namespace std;

// O(n^2)
/*
dp[i][num] = LIS of nums[0:i+1] and last number = num
dp[i][nums[i]] = MAX_{0 <= num < nums} dp[i][num] + 1 (if num == nums[i])
dp[i][num] = dp[i][num] + 1 (else)
*/
// 39:21
int solution1(const vector<int> &nums){
    const int n = nums.size();
    const int MAX = 10000;
    const int inf = 100000000;
    vector<vector<int>> dp(n, vector<int>(2 * MAX + 1, 0));
    dp[0][nums[0] + MAX] = 1;
    for (int i = 1; i < n; i++){
        dp[i] = dp[i-1];
        dp[i][nums[i] + MAX] = max(dp[i-1][nums[i] + MAX], *max_element(begin(dp[i]), begin(dp[i]) + nums[i] + MAX) + 1);
    }
    return *max_element(begin(dp.back()), end(dp.back()));
}

// O(nlogn)
/*
dp[i] = minimum value of the last element of LIS of length i+1
then dp is increasing sequence
insert nums[i] to upper_bound(begin(dp), end(dp), nums[i])
ex. [0,1,0,3,2,3]
dp = [0, 1, INF, INF, INF]
*/
// 
int solution2(const vector<int> &nums){
    const int N = nums.size();
    const int INF = 10000000;
    vector<int> dp(N+1, INF);
    dp[0] = nums[0];
    for (int i = 1; i < N; i++){
        *lower_bound(begin(dp), end(dp), nums[i]) = nums[i];
    }
    int answer = 0;
    for (int i = 0; i < N; i++){
        if (dp[i+1] == INF){
            answer = i+1;
            break;
        }
    }
    return answer;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return solution2(nums);
    }
};
