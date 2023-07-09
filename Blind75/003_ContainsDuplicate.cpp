// O(NlogN)
// 03:33
bool solution1(vector<int> &nums){
    map<int, int> count_nums;
    for (auto &i: nums){
        count_nums[i]++;
    }
    for (auto &i: count_nums){
        if (i.second > 1){
            return true;
        }
    }
    return false;
}

// O(N)
// 00:10
bool solution2(vector<int> &nums){
    unordered_map<int, int> count_nums;
    for (auto &i: nums){
        count_nums[i]++;
    }
    for (auto &i: count_nums){
        if (i.second > 1){
            return true;
        }
    }
    return false;
}

// O(NlogN)
// 03:00
bool solution3(vector<int> nums){
    sort(begin(nums), end(nums));
    for (int i = 0; i < nums.size() - 1; i++){
        if (nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}
