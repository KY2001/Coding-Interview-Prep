using namespace std;

/*
easy -> wrong answer
*/
// O(|nums|)
int solution1(const vector<int> &nums){
    const int n = nums.size();
    int odd_sum = 0;
    int even_sum = 0;
    for (int i = 0; i < n; i++){
        if (i%2){
            odd_sum += nums[i];
        }else{
            even_sum += nums[i];
        }
    }
    return max(odd_sum, even_sum);
}

/*
n = |nums|
1 <= n <= 400
0 <= nums[i] <= 400
*/
// O(|nums|)
// 09:22
int solution2(const vector<int> &nums){
    const int n = nums.size();
    int sum_used = nums[0];
    int sum_unused = 0;
    for (int i = 1; i < n; i++){
        const int max_sum = max(sum_used, sum_unused);
        sum_used = sum_unused + nums[i];
        sum_unused = max_sum;
    }
    return max(sum_used, sum_unused);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        return solution2(nums);
    }
};
