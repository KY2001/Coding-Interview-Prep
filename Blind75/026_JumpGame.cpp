using namespace std;

/*
already[i] = can get to index i or not
*/
// O(|nums|)
// 10:28
bool solution1(const vector<int> &nums){
    const int n = nums.size();
    int max_idx = 0;
    for (int i = 0; i < n; i++){
        if (i > max_idx){
            return false;
        }
        max_idx = max(max_idx, i + nums[i]);
    }
    return true;
}

class Solution {
public:
    bool canJump(vector<int>& nums) {
        return solution1(nums);
    }
};
