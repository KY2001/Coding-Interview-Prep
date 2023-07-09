using namespace std;

// O(m * n)
// 11:00
int solution1(vector<vector<char>>& input_grid){
    const int m = input_grid.size();
    const int n = input_grid[0].size();
    vector<string> grid(m+2, string('-1', n+2));
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            grid[x+1][y+1] = input_grid[x][y];
        }
    }
    int answer = 0;
    vector<vector<bool>> already(m+2, vector<bool>(n+2));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (already[i+1][j+1] or grid[i+1][j+1] != '1') continue;
            deque<pair<int, int>> unvisited = {{i+1, j+1}};
            answer++;
            while(unvisited.size()){
                const int x = unvisited[0].first;
                const int y = unvisited[0].second;
                unvisited.pop_front();
                if (already[x][y] or grid[x][y] != '1') continue;
                already[x][y] = true;
                unvisited.push_back({x+1, y});
                unvisited.push_back({x-1, y});
                unvisited.push_back({x, y+1});
                unvisited.push_back({x, y-1});
            }
        }
    }
    return answer;
}

// O(m * n)
// 15:13
int solution2(vector<vector<char>>& input_grid){
    const int m = input_grid.size();
    const int n = input_grid[0].size();
    vector<string> grid(m+2, string('-1', n+2));
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            grid[x+1][y+1] = input_grid[x][y];
        }
    }
    int answer = 0;
    vector<vector<bool>> already(m+2, vector<bool>(n+2));
    auto dfs = [&](auto self, int x, int y){
        if (grid[x][y] != '1' or already[x][y]) return;
        already[x][y] = true;
        self(self, x+1, y);
        self(self, x-1, y);
        self(self, x, y+1);
        self(self, x, y-1);
    };
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            if (grid[x+1][y+1] != '1' or already[x+1][y+1]) continue;
            answer++;
            dfs(dfs, x+1, y+1);
        }
    }
    return answer;
}

// O(m * n)
// 19:05
int solution3(vector<vector<char>>& input_grid){
    const int m = input_grid.size();
    const int n = input_grid[0].size();
    vector<string> grid(m+2, string('-1', n+2));
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            grid[x+1][y+1] = input_grid[x][y];
        }
    }
    int answer = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (grid[i+1][j+1] != '1') continue;
            const deque<pair<int, int>> unvisited = {{i+1, j+1}};
            answer++;
            while(unvisited.size()){
                const int x = unvisited[0].first;
                const int y = unvisited[0].second;
                unvisited.pop_front();
                if (grid[x][y] != '1') continue;
                grid[x][y] = '2';
                unvisited.push_back({x+1, y});
                unvisited.push_back({x-1, y});
                unvisited.push_back({x, y+1});
                unvisited.push_back({x, y-1});
            }
        }
    }
    return answer;
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        return solution3(grid);
    }
};
