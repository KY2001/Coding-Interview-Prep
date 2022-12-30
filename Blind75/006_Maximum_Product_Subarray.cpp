bool contains_zero(vector<int> &nums){
    for (auto &num: nums){
        if (num == 0) return true;
    }
    return false;
}

vector<vector<int>> remove_zeros(vector<int> &nums){
    vector<vector<int>> result;
    vector<int> save;
    for (int i = nums.size()-1; i >= 0; i--){
        if (nums[i] == 0 and save.size()){
            reverse(begin(save), end(save));
            result.push_back(save);
            save.clear();
        }else if (nums[i] != 0){
            save.push_back(nums[i]);
        }
    }
    if (save.size()) result.push_back(save);
    return result;
}

int get_max(vector<int> &nums){
    int count_minus = 0;
    long long product = 1;
    int answer = nums[0];
    if (nums.size() == 1){
        return answer;
    }
    for (auto &num: nums){
        if (num < 0){
            count_minus++;
        }
        product *= num;
    }
    if (count_minus % 2){
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0){
                int product_back = 1;
                for (int j = i+1; j < nums.size(); j++){
                    product_back *= nums[j];
                }
                answer = max(answer, product_back);
            }
        }
        for (int i = nums.size()-1; i >= 0; i--){
            if (nums[i] < 0){
                int product_front = 1;
                for (int j = i-1; j >= 0; j--){
                    product_front *= nums[j];
                }
                answer = max(answer, product_front);
            }
        }
    }else{
        answer = product;
    }
    return answer;
}

// O(N)
// 29:46
int solution1(vector<int> &nums){
    int answer = 0;
    if (contains_zero(nums)){
        vector<vector<int>> nums_split = remove_zeros(nums);
        for (auto &num_split: nums_split){
            // for (auto &num: num_split) cout << num << " ";
            // cout << endl;
            answer = max(answer, get_max(num_split));
        }
    }else{
        answer =  get_max(nums);
    }
    return answer;
}

int get_max2(vector<int> &nums){
    int count_minus = 0;
    int product = 1;
    int answer = nums[0];
    if (nums.size() == 1){
        return answer;
    }
    for (auto &num: nums){
        if (num < 0){
            count_minus++;
        }
        product *= num;
    }
    if (count_minus % 2){
        int product_front = 1;
        for (int i = 0; i < nums.size(); i++){
            product_front *= nums[i];
            if (nums[i] < 0){
                answer = max(answer, product/product_front);
            }
        }
        int product_back = 1;
        for (int i = nums.size()-1; i >= 0; i--){
            product_back *= nums[i];
            if (nums[i] < 0){
                answer = max(answer, product/product_back);
            }
        }
    }else{
        answer = product;
    }
    return answer;
}

// O(N)
// 40:21
int solution2(vector<int> &nums){
    int answer = *max_element(begin(nums), end(nums));
    vector<vector<int>> nums_split = remove_zeros(nums);
    for (auto &num_split: nums_split){
        // for (auto &num: num_split) cout << num << " ";
        // cout << endl;
        answer = max(answer, get_max2(num_split));
    }
    return answer;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return solution2(nums);
    }
};