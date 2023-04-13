# include <bits/stdc++.h>

using namespace std;

bool all_visited(vector<bool> &already){
    for (int i = 0; i < already.size(); i++){
        if (!already[i]) return false;
    }
    return true;
}


// 1 <= n <= 2000
// 0 <= |edges| <= 5000
// O(N)
// 13:49
bool solve(const int n, const vector<vector<int>> &edges){
    vector<vector<int>> graph(n);
    for (auto &edge: edges){
        int a = edge[0];
        int b = edge[1];
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<bool> already(n);
    deque<pair<int, int>> to_visit = {{0, -1}};
    while(to_visit.size()){
        const int current_node = to_visit[0].first;
        const int prev_node = to_visit[0].second;
        already[current_node] = true;
        to_visit.pop_front();
        for (auto next_node: graph[current_node]){
            if (next_node != prev_node and already[next_node]){
                return false;
            } else if (!already[next_node]) {
                to_visit.push_back({next_node, current_node});
            }
        }
    }
    if (!all_visited(already)) return false;
    return true;
}

// int main(int n, vector<vector<int>> &edges){
//     return solve(n, edges);
// }

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        return solve(n, edges);
    }
};
