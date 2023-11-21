#include<bits/stdc++.h>

using namespace std;

// Time: O(log n)
// Space: O(1)
// 07:13

int solve(const vector<int> &nums, const int target) {
  const int n = nums.size();
  if (n == 1) {
    if (nums[0] >= target) {
      return 0;
    }
    return 1;
  }

  int left = 0;
  int right = nums.size();
  while(right - left > 1) {
    const int mid = (left + right) / 2;
    if (nums[mid] > target) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if (nums[left] > target) {
    return 0;
  }
  if (nums[left] == target) {
    return left;
  }
  return left + 1;
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};
