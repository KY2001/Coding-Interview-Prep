import java.util.List;

// 35:00
// Time: O(n^3)
// Space: O(n)

public class Solution {
  public static void main(String[] args) {

  }

  public int minimumSumSubarray(List<Integer> nums, int l, int r) {
      return solve(nums, l, r);
  }

  public int solve(List<Integer> nums, int l, int r) {
    final int n = nums.size();
    int minimum_sum = Integer.MAX_VALUE;
    for (int s = 0; s < n; s++) {
      for (int length = l; length <= r && s + length <= n; length++) {
        int sum = 0;
        for (int i = 0; i < length; i++) {
          sum += nums.get(s + i);
        }
        if (sum > 0 && sum < minimum_sum) {
          minimum_sum = sum;
        }
      }
    }

    if (minimum_sum == Integer.MAX_VALUE) {
      return -1;
    }

    return minimum_sum;
  }
}
