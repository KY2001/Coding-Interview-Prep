using namespace std;

// https://r2.whiteboardfox.com/21726654-2658-3529
// O(log(N))
// 16:28
int solution1(const vector<int> &nums, int target){
    if (nums.size() == 1) return (target == nums[0] ? 0 : -1);
    if (nums[0] < nums.back()){
        int index = distance(begin(nums), lower_bound(begin(nums), end(nums), target));
        if (index >= nums.size()) return -1;
        return (nums[index] == target ? index : -1);
    }
    int L = 0;
    int R = nums.size() - 1;
    while(R - L > 1){
        int mid = (R + L) / 2;
        if (nums[mid] >= nums[0]){
            L = mid;
        }else{
            R = mid;
        }
    }
    int index;
    if (target >= nums[0]){
        R = L;
        L = 0;
        index = distance(begin(nums), lower_bound(begin(nums), begin(nums) + R, target));
    }else{
        L = R;
        R = nums.size() - 1;
        index = distance(begin(nums), lower_bound(begin(nums)+L, end(nums), target));
    }
    if (index >= nums.size()) return -1;
    return (nums[index] == target ? index : -1);
}

// O(log(N))
// 41:08
// 2つの二分探索を1つに圧縮
int solution2(const vector<int> &nums, int target){
    if (nums.size() == 1) return (target == nums[0] ? 0 : -1);
    if (nums[0] < nums.back()){
        int index = distance(begin(nums), lower_bound(begin(nums), end(nums), target));
        if (index >= nums.size()) return -1;
        return (nums[index] == target ? index : -1);
    }
    int L = 0;
    int R = nums.size();
    if (target >= nums[0]){
        while(R - L > 1){
            int mid = (R + L) / 2;
            if (nums[mid] <= target and nums[mid] >= nums[0]){
                L = mid;
            }else{
                R = mid;
            }
        }
    }else{
        while(R - L > 1){
            int mid = (R + L) / 2;
            if (nums[mid] <= target or nums[mid] >= nums[0]){
                L = mid;
            }else{
                R = mid;
            }
        }
    }
    return (nums[L] == target ? L : -1);
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return solution2(nums, target);
    }
};
