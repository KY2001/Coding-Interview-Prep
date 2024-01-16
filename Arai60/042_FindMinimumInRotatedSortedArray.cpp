#include <bits/stdc++.h>

using namespace std;

// [0, 1, 2, 3, 4]
// [3, 4, 0, 1, 2]
// for the most index nums[i] < nums[i+1]
// [L, R]
// mid = (L+R)/2
// if mid > L -> L = mid
// else R = mid

// [3,4,5,1,2]
// [1, 2, 3, 4, 5]

// 15:07
// Time: O(log(n))
// Space: O(1)

int solve(const vector<int> &nums) {
  const int n = nums.size();

  if (nums[0] < nums[n - 1]) {
    return nums[0];
  }
  
  int L = 0;
  int R = n-1;
  while(R - L > 1) {
    const int mid = (L + R) / 2;
    if (nums[mid] > nums[L]) {
      L = mid;
    } else {
      R = mid;
    }
  }
  return nums[R];
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        return solve(nums);
    }
};
