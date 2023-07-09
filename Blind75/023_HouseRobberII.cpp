using namespace std;

// O(|nums|^2)
/*
1 <= |nums| <= 100
0 <= nums[i] <= 1000

nums = [1, 2, 3, 4]
*/
// 16:52
int solution1(const vector<int> &nums){
    const int n = nums.size();
    if (n <= 3) {
        return *max_element(begin(nums), end(nums));
    }

    int answer = 0;
    for (int i = 0; i < n; i++){
        const int unused_idx = (i - 1 + n) % n;
        int sum_used = nums[i] + nums[(i+2) % n];
        int sum_unused = nums[i];
        for (int j = 0; j < n; j++){
            const int idx = (j + i + 3) % n;
            if (idx == unused_idx) break;
            int sum_max = max(sum_used, sum_unused);
            sum_used = sum_unused + nums[idx];
            sum_unused = sum_max;
        }
        answer = max({answer, sum_used, sum_unused});
    }
    return answer;
}


class Solution {
public:
    int rob(vector<int>& nums) {
        return solution1(nums);
    }
};