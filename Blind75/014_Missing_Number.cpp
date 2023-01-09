using namespace std;

// O(N)
// 03:49
int solution1(const vector<int> &nums){
    const int n = nums.size();
    unordered_set<int> check;
    for (int num: nums){
        check.insert(num);
    }
    int answer;
    for (int i = 0; i <= n; i++){
        if (!check.count(i)){
            answer = i;
            break;
        }
    }
    return answer;
}

// O(N)
// 07:04
int solution2(const vector<int> &nums){
    const int n = nums.size();
    vector<bool> check(n+1);
    for (int num : nums){
        check[num] = true;
    }
    int answer;
    for (int i = 0; i <= n; i++){
        if (!check[i]){
            answer = i;
            break;
        }
    }
    return answer;
}

// O(N)
// 10:30
int solution3(const vector<int> &nums){
    const int n = nums.size();
    const int sum = accumulate(begin(nums), end(nums), 0);
    return n * (n+1) / 2 - sum;
}

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return nums.size() * (nums.size()+1) / 2 - accumulate(begin(nums), end(nums), 0);
    }
};
