// O(n)
// 10:19
// [1, 2, 3, 4]
// [1, 1, 2, 6]
// [24, 12, 8, 6]
vector<int> solution1(vector<int> &nums){
    int n = nums.size();
    vector<int> answer(n, 1);
    int product = 1;
    for (int i = 0; i < n-1; i++){
        product *= nums[i];
        answer[i+1] *= product;
    }
    product = 1;
    for (int i = n-1; i >= 1; i--){
        product *= nums[i];
        answer[i-1] *=  product;
    }
    return answer;
}

vector<int> solution2(vector<int> &nums){
    int n = nums.size();
    vector<int> answer(n, 1);
    for (int i = 0; i < n-1; i++){
        answer[i+1] *= nums[i] * answer[i];
    }
    int product = 1;
    for (int i = n-1; i >= 1; i--){
        product *= nums[i];
        answer[i-1] *=  product;
    }
    return answer;
}
