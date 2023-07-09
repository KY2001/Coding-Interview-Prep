#include <bits/stdc++.h>

using namespace std;


// 0 <= |nums| <= 10^5
// -10^9 <= nums[i] <= 10^9
// O(NlogN)
// 15:00
int solve1(vector<int> &nums){
    if (nums.empty()){
        return 0;
    }
    const int n = nums.size();
    sort(begin(nums), end(nums));
    int max_count = 1;
    int count = 1;
    int prev = nums[0];
    for (int i = 1; i < n; i++){
        const int num = nums[i];
        if (num == prev + 1){
            count++;
        }else if (num != prev) {
            max_count = max(max_count, count);
            count= 1;
        }
        prev = num;
    }
    max_count = max(max_count, count);
    return max_count;
}


// O(N)
// 24:31
int solve2(vector<int> &nums){
    if (nums.empty()){
        return 0;
    }
    const int n = nums.size();
    unordered_map<int, bool> numbers;
    unordered_map<int, bool> already_checked;
    for (auto &num: nums) {
        numbers[num] = true;
    }
    int max_count = 0;
    for (auto &num: nums){
        if (already_checked.count(num)){
            continue;
        }
        int count = 1;
        for (int next_num = num - 1; ; next_num--){
            if (numbers.count(next_num)){
                count++;
                already_checked[next_num] = true;
            } else {
                break;
            }
        }
        for (int next_num = num + 1; ; next_num++){
            if (numbers.count(next_num)){
                count++;
                already_checked[next_num] = true;
            } else {
                break;
            }
        }
        max_count = max(max_count, count);
    }
    return max_count;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        return solve2(nums);
    }
};
