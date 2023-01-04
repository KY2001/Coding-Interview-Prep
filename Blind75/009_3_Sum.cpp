using namespace std;

// O(N^2log(N)) too slow
// 57:09
vector<vector<int>> solution1(vector<int> nums){
    sort(begin(nums), end(nums));
    vector<vector<int>> answer;
    vector<int> triplet;
    for (int i = 0; i < nums.size() - 2; i++){
        for (int j = i+1; j < nums.size() - 1; j++){
            int nums_k = - (nums[i] + nums[j]);
            auto iter = lower_bound(begin(nums)+j+1, end(nums), nums_k);
            if (iter == end(nums)) continue;
            if (*iter == nums_k){
                triplet = {nums[i], nums[j], nums_k};
                if (answer.size()){
                    if (answer.back() >= triplet) continue;
                }
                answer.push_back(triplet);
            }
        }
    }
    return answer;
}

vector<int> remove_three_duplicates(vector<int> &nums){
    vector<int> nums_ret = {nums[0], nums[1], nums[2]};
    for (int i = 3; i < nums.size(); i++){
        if (nums[i] == nums[i-1] and nums[i-1] == nums[i-2] and nums[i-2] == nums[i-3]) continue;
        nums_ret.emplace_back(nums[i]);
    }
    return nums_ret;
}

// O(N^2log(N)) too slow
// 76:35
vector<vector<int>> solution2(vector<int> nums){
    nums = remove_three_duplicates(nums);
    sort(begin(nums), end(nums));
    vector<vector<int>> answer;
    vector<int> triplet;
    for (int i = 0; i < nums.size() - 2; i++){
        for (int j = i+1; j < nums.size() - 1; j++){
            int nums_k = - (nums[i] + nums[j]);
            auto iter = lower_bound(begin(nums)+j+1, end(nums), nums_k);
            if (iter == end(nums)) continue;
            if (*iter == nums_k){
                triplet = {nums[i], nums[j], nums_k};
                if (answer.size()){
                    if (answer.back() >= triplet) continue;
                }
                answer.push_back(triplet);
            }
        }
    }
    return answer;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return solution2(nums);
    }
};
