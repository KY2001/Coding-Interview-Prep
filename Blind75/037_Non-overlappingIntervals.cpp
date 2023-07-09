#include<bits/stdc++.h>

using namespace std;

bool is_overlap(vector<int> &interval1, vector<int> &interval2){
    if (interval1[1] <= interval2[0]) return false;
    if (interval2[1] <= interval1[0]) return false;
    return true;
}

// 1<= |intervals| <= 10^5
// -5 * 10^4 <= start <= end <= 5 * 10^4
// https://jamboard.google.com/d/1Rl95k0RhBTRJm445zItstZHhFn66oRFMOAS6v0KbQMM/edit?usp=sharing
// time: O(n)
// space: O(n)
// 25:16
int solve(vector<vector<int>>& intervals) {
    const int n = intervals.size();
    sort(begin(intervals), end(intervals));
    const int invalid = -100000;
    int answer = 0;
    for (int i = 0; i < n - 1; i++){
        if (intervals[i][0] == invalid) continue;
        for (int j = i+1; j < n; j++){
            if (intervals[j][0] == invalid) continue;
            if (is_overlap(intervals[i], intervals[j])){
                answer++;
                if (intervals[i][1] >= intervals[j][1]){
                    intervals[i][0] = invalid;
                    break;
                }else{
                    intervals[j][0] = invalid;
                }
            }else{
                break;
            }
        }
    }
    return answer;
}

// int main(){

// }

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        return solve(intervals);
    }
};
