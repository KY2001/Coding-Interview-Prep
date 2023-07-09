/*
choose (i, j) such that i < j
 -> water's area = (j - i) * min(height[i], height[j])
*/

using namespace std;

// O(Nlog(N))
// 13:41
int solution1(const vector<int> &height){
    int n = height.size();
    vector<pair<int, int>> height_index(n);
    for (int i = 0; i < n; i++){
        height_index[i] = {height[i], i};
    }
    sort(begin(height_index), end(height_index));
    set<pair<int, int>> index_height;
    for (int i = 0; i < n; i++){
        index_height.insert({i, height[i]});
    }
    int answer = 0;
    for (auto &hi : height_index){
        if (index_height.size() == 1) break;
        int h = hi.first;
        int i = hi.second;
        index_height.erase({i, h});
        answer = max({answer, h * abs(i - (*begin(index_height)).first), h * abs(i - (*rbegin(index_height)).first)});
    }
    return answer;
}

// O(NlogN)
// 33:57
int solution2(const vector<int> &height){
    int n = height.size();
    vector<pair<int, int>> height_index(n);
    for (int i = 0; i < n; i++){
        height_index[i] = {height[i], i};
    }
    sort(begin(height_index), end(height_index));
    vector<int> MIN(n), MAX;
    for (int i = 0; i < n; i++){
        MIN[i] = height_index[i].second;
    }
    MAX = MIN;
    for (int i = n-2; i >= 0; i--){
        MIN[i] = min(MIN[i], MIN[i+1]);
        MAX[i] = max(MAX[i], MAX[i+1]);
    }
    int answer = 0;
    for (int i = 0; i < n-1; i++){
        auto [h, j] = height_index[i];
        answer = max(answer, h * max(abs(j - MIN[i+1]), abs(j - MAX[i+1])));
    }
    return answer;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        return solution2(height);
    }
};
