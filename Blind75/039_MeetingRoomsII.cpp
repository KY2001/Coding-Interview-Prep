#include <bits/stdc++.h>

using namespace std;

// 1 <= N <= 10^4
// 0 <= start < end <= 10^6
// time: O(N)
// space: O(NlogN)
// 13:00
// 累積和は「culmulative sum」ではなく「cumulative sum」
int solve(const vector<vector<int>> &intervals){
    const int N = intervals.size();
    vector<int> all_position(2 * N);
    for (int i = 0; i < N; i++){
        all_position[i] = intervals[i][0];
        all_position[N + i] = intervals[i][1];
    }
    sort(begin(all_position), end(all_position));
    unordered_map<int, int> mapping;
    for (int i = 0; i < 2 * N; i++){
        mapping[all_position[i]] = i;
    }
    vector<int> culmulative_sum(2 * N);
    for (auto &interval: intervals){
        culmulative_sum[mapping[interval[0]]]++;
        culmulative_sum[mapping[interval[1]]]--;
    }
    for (int i = 0; i < 2 * N - 1; i++){
        culmulative_sum[i+1] += culmulative_sum[i];
    }
    return *max_element(begin(culmulative_sum), end(culmulative_sum));
}

// time: O(M)
// space: O(M)
// 14:50
int solve2(const vector<vector<int>> &intervals){
    const int N = intervals.size();
    const int M = 1000000;
    vector<int> culmulative_sum(2 * M);
    for (auto &interval: intervals){
        culmulative_sum[interval[0]]++;
        culmulative_sum[interval[1]]--;
    }
    for (int i = 0; i < 2 * M - 1; i++){
        culmulative_sum[i+1] += culmulative_sum[i];
    }
    return *max_element(begin(culmulative_sum), end(culmulative_sum));
}

// int main(){

// }

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        return solve2(intervals);
    }
};
