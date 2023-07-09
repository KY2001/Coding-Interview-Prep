#include <bits/stdc++.h>

using namespace std;

bool is_overlap(vector<int> &interval1, vector<int> &interval2) {
    if (interval1[1] < interval2[0]) return false;
    if (interval1[0] > interval2[1]) return false;
    return true;
}

vector<int> merge(vector<int> &interval1, vector<int> &interval2){
    return {min(interval1[0], interval2[0]), max(interval1[1], interval2[1])};
}

// 1 <= |intervals| <= 10^4
// 0 <= start <= end <= 10^4
// https://jamboard.google.com/d/15JZ0eMibpqM6JeY8GLByrwL7QF1QXYt-YYXgpDVCElg/edit?usp=sharing
// time: O(N)
// space: O(N)
// 10:38
vector<vector<int>> solve(vector<vector<int>> &intervals){
    sort(begin(intervals), end(intervals));
    const int n = intervals.size();
    for (int i = 0; i < n - 1; i++){
        if (intervals[i][0] == -1) continue;
        for (int j = i+1; j < n; j++){
            if (is_overlap(intervals[i], intervals[j])){
                intervals[i] = merge(intervals[i], intervals[j]);
                intervals[j] = {-1, -1};
            } else {
                break;
            }
        }
    }
    vector<vector<int>> answer;
    for (auto &interval: intervals){
        if (interval[0] != -1){
            answer.push_back(interval);
        }
    }
    return answer;
}

// int main(){
// }

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return solve(intervals);
    }
};
