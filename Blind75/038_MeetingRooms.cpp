#include<bits/stdc++.h>

using namespace std;

bool is_overlap(vector<int> &interval1, vector<int> &interval2){
    if (interval1[1] <= interval2[0]) return false;
    if (interval2[1] <= interval1[0]) return false;
    return true;
}

// 0 <= |intervals| <= 10^4
// 0 <= start < end <= 10^6
// time: O(NlogN)
// space: O(N)
// 5:24
bool solve(vector<vector<int>>& intervals){
    sort(begin(intervals), end(intervals));
    const int N = intervals.size();
    for (int i = 0; i < N - 1; i++){
        if (is_overlap(intervals[i], intervals[i+1])) return false;
    }
    return true;
}

// int main(){

// }

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        return solve(intervals);
    }
};
