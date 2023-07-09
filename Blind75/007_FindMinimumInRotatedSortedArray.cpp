// [4, 5, 1, 2, 3]
// (L, R) = (0, 5) -> mid = 2
// (L, R) = (0, 2) -> mid = 1
// (L, R) = 
// 14:38
// LとRを半開区間にしてバグらせた -> LとRの定義を初めに明確化する
// 単調性：monotonicity
// 単調増加：monotonically increase
int solution1(vector<int> &nums){
    int n = nums.size();
    if (n == 1) return nums[0];
    if (nums[0] < nums[n-1]) return nums[0];
    int L = 0;
    int R = nums.size()-1;
    int mid;
    while(R - L > 1){
        mid = (R + L)/2;
        if (nums[mid] > nums[R]){
            L = mid;
        }else{
            R = mid;
        }
    }
    return nums[R];
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        return solution1(nums);
    }
};
