// O(N)
// 09:14
int solution1(vector<int> &nums){
    int n = nums.size();
    vector<int> cum_sum(n+1, 0);
    for (int i = 0; i < n; i++){
        cum_sum[i+1] = nums[i] + cum_sum[i];
    }
    int answer = nums[0];
    int max_value_seen = cum_sum.back();
    for (int i = n-1; i >= 0; i--){
        answer = max(answer, max_value_seen - cum_sum[i]);
        max_value_seen = max(max_value_seen, cum_sum[i]);
    }
    return answer;
}

// solution1の微妙な箇所を修正
int solution1_modified(vector<int> &nums){
    int n = nums.size();
    vector<int> cum_sum(n+1, 0);
    // for (int i = 0; i < n; i++){
    //     cum_sum[i+1] = nums[i] + cum_sum[i];
    // }
    copy(begin(nums), end(nums), begin(cum_sum)+1);
    for (int i = 0; i < n; i++){
        cum_sum[i+1] += cum_sum[i];
    }
    int answer = nums[0];
    int max_value_seen = cum_sum.back();
    for (int i = n-1; i >= 0; i--){
        answer = max(answer, max_value_seen - cum_sum[i]);
        max_value_seen = max(max_value_seen, cum_sum[i]);
    }
    return answer;
}

// 累積和の配列を別に持たないので、空間計算量が減るが、、、
int solution2(vector<int> &nums){
    int n = nums.size();
    for (int i = 0; i < n-1; i++){
        nums[i+1] += nums[i];
    }
    int answer = nums[0];
    int max_value_seen = nums.back();
    for (int i = n-2; i >= 0; i--){
        answer = max(answer, max_value_seen - nums[i]);
        max_value_seen = max(max_value_seen, nums[i]);
    }
    return max(answer, max_value_seen);
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return solution2(nums);
    }
};
