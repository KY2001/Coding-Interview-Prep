#include <bits/stdc++.h>

using namespace std;

void dfs(const int current_node, vector<bool> &already_visited, vector<vector<int>> &graph){
    already_visited[current_node] = true;
    for (auto next_node: graph[current_node]){
        if (!already_visited[next_node]) dfs(next_node, already_visited, graph);
    }
}

// 9:19
// time: O(N)
// space: O(N)
int solve(const int n, const vector<vector<int>> &edges){
    vector<vector<int>> graph(n);
    for (auto &edge: edges){
        const int a = edge[0];
        const int b = edge[1];
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<bool> already_visited(n);
    int components_count = 0;
    for (int node = 0; node < n; node++){
        if (already_visited[node]) continue;
        dfs(node, already_visited, graph);
        components_count++;
    }
    return components_count;
}


// int main(){

// }

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        return solve(n, edges);
    }
};
