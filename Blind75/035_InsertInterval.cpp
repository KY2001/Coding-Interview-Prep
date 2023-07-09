#include <bits/stdc++.h>

using namespace std;

// 0 <= |Intervals| <= 10^4
// 0 <= start <= end <= 10^5
// https://jamboard.google.com/d/1AC3uM_w-Us2pzA6RhzbDJXLs7WpoyJrrBhYoe2P8OAQ/edit?usp=sharing
// time: O(N)
// space: O(N)
// 37:10
vector<vector<int>> solve(const vector<vector<int>> &intervals, const vector<int> &newInterval){
    const int n = intervals.size();
    if (n == 0) {
        return {newInterval};
    }
    vector<int> starts(n);
    vector<int> ends(n);
    for (int i = 0; i < n; i++){
        starts[i] = intervals[i][0];
        ends[i] = intervals[i][1];
    }
    auto L = lower_bound(begin(ends), end(ends), newInterval[0]);
    auto R = prev(upper_bound(begin(starts), end(starts), newInterval[1]));
    const int L_idx = distance(begin(ends), L);
    const int R_idx = distance(begin(starts), R);
    vector<vector<int>> answer;
    if (R_idx < 0) {
        answer.push_back(newInterval);
    }
    if (R_idx < L_idx) {
        for (int i = 0; i < n; i++){
            answer.push_back(intervals[i]);
            if (i == R_idx) answer.push_back(newInterval);
        }
    } else if (R_idx == L_idx) {
        const int L_interval = min(newInterval[0], starts[L_idx]);
        const int R_interval = max(newInterval[1], ends[R_idx]);
        for (int i = 0; i < n; i++){
            if (i == R_idx) {
                answer.push_back({L_interval, R_interval});
                continue;
            }
            answer.push_back(intervals[i]);
        }
    }else{
        const int L_interval = min(newInterval[0], starts[L_idx]);
        const int R_interval = max(newInterval[1], ends[R_idx]);
        for (int i = 0; i < n; i++){
            if (i == L_idx) {
                answer.push_back({L_interval, R_interval});
                continue;
            } else if (L_idx < i and i <= R_idx) {
                continue;
            }
            answer.push_back(intervals[i]);
        }
    }
    return answer;
}

bool overlap(vector<int> &interval, vector<int> &newInterval){
    if (interval[1] < newInterval[0]) return false;
    if (interval[0] > newInterval[1]) return false;
    return true;
}

// 1:03:02
// time: O(N)
// space: O(N)
vector<vector<int>> solve2(vector<vector<int>> &intervals, vector<int> &newInterval){
    const int n = intervals.size();
    if (n == 0) {
        return {newInterval};
    }
    for (auto &interval: intervals){
        if (overlap(interval, newInterval)){
            newInterval[0] = min(newInterval[0], interval[0]);
            newInterval[1] = max(newInterval[1], interval[1]);
            interval[0] = -1;
        }
    }
    vector<vector<int>> answer;
    bool newInterval_added = false;
    for (auto &interval: intervals){
        if (interval[0] == -1) continue;
        if (!newInterval_added and interval[0] >= newInterval[0]) {
            answer.push_back(newInterval);
            newInterval_added = true;
        }
        answer.push_back(interval);
    }
    if (!newInterval_added) {
        answer.push_back(newInterval);
    }
    return answer;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return solve2(intervals, newInterval);
    }
};
