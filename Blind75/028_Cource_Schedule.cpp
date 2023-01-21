using namespace std;

/*
whiteboard: https://jamboard.google.com/d/1lWPRLxiTp9NfboTkbLePyHCgvF4R5bV-b2LNzZlS50E/edit?usp=sharing
find whether the graph has cycles or not.
Do DFS.
1 <= numCourses <= 2000
1 <= |prerequisites| <= 5000
隣接リスト：adjacency list
*/
// O(numCourses + |prerequisites|)
// 26:35
void dfs(int node, vector<vector<int>>& graph, vector<int>& already_visited, bool& answer){
    already_visited[node] = 2;
    for (int to : graph[node]){
        if (already_visited[to] == 2){
            answer = false;
        }else if (!already_visited[to]){
            dfs(to, graph, already_visited, answer);
        }
    }
    already_visited[node] = 1;
}

bool solution1(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < prerequisites.size(); i++){
        const int a = prerequisites[i][0];
        const int b = prerequisites[i][1];
        graph[b].push_back(a);
    }
    vector<int> already_visited(numCourses);
    bool answer = true;
    for (int i = 0; i < numCourses; i++){
        if (already_visited[i]) continue;
        dfs(i, graph, already_visited, answer);
    }
    return answer;
}

bool solution2(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < prerequisites.size(); i++){
        const int a = prerequisites[i][0];
        const int b = prerequisites[i][1];
        graph[b].push_back(a);
    }
    vector<int> already_visited(numCourses);
    bool answer = true;
    // ラムダ式
    // [&]と書くことでラムダ式の外の変数を利用できる。
    auto dfs2 = [&](auto self, int node) -> void {
        already_visited[node] = 2;
        for (int to : graph[node]){
            if (already_visited[to] == 2){
                answer = false;
            }else if (!already_visited[to]){
                self(self, to);
            }
        }
        already_visited[node] = 1;
    };
    for (int i = 0; i < numCourses; i++){
        if (already_visited[i]) continue;
        dfs2(dfs2, i);
    }
    return answer;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return solution1(numCourses, prerequisites);
    }
};