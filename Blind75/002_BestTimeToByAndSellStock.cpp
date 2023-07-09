// 04:43
// time complexity: O(N)
int solution1(vector<int> &prices){
    int n = prices.size();
    if (n == 1) return 0;
    vector<int> max_after_ith_day(n-1);
    max_after_ith_day[n-2] = prices[n-1];
    for (int i = n-3; i >= 0; i--){
        max_after_ith_day[i] = max(prices[i+1], max_after_ith_day[i+1]);
    }
    int answer = 0;
    for (int i = 0; i < n-1; i++){
        answer = max(answer, max_after_ith_day[i] - prices[i]);
    }
    return answer;
}

// 01:57
// time complexity: O(N)
int solution2(vector<int> &prices){
    int n = prices.size();
    int answer = 0;
    int max_after_now = prices.back();
    for (int i = n - 2; i >= 0; i--){
        answer = max(answer, max_after_now - prices[i]);
        max_after_now = max(max_after_now, prices[i]);
    }
    return answer;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solution2(prices);
    }
};
