// accept後、chatGPTで添削する。

using namespace std;

/*
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5 // 10^5って英語でなんていう？


*/

// vector<vector<int>> solution1(const vector<vector<int>>& heights){
//     const int m = heights.size();
//     const int n = heights[0].size();
//     vector<vector<bool>> can_flow_to_pacific(m, vector<bool>(n));
//     for (int x = 0; x < m; x++){
//         for (int y = 0; y < n; y++){
//             if (y == 0 or x == 0){
//                 can_flow_to_pacific[x][y] = true;
//             }else if (heights[x][y] >= heights[x-1][y] and can_flow_to_pacific[x-1][y]){
//                 can_flow_to_pacific[x][y] = true;
//             }else if (heights[x][y] >= heights[x][y-1] and can_flow_to_pacific[x][y-1]){
//                 can_flow_to_pacific[x][y] = true;
//             }
//         }
//     }
//     vector<vector<bool>> can_flow_to_atlantic(m, vector<bool>(n));
//     for (int x = m-1; x >= 0; x--){
//         for (int y = n - 1; y >= 0; y--){
//             if (x == m-1 or y == n - 1){
//                 can_flow_to_atlantic[x][y] = true;
//             }else if (heights[x][y] >= heights[x+1][y] and can_flow_to_atlantic[x+1][y]){
//                 can_flow_to_atlantic[x][y] = true;
//             }else if (heights[x][y] >= heights[x][y+1] and can_flow_to_atlantic[x][y+1]){
//                 can_flow_to_atlantic[x][y] = true;
//             }
//         }
//     }
//     vector<vector<int>> answer;
//     for (int x = 0; x < m; x++){
//         for (int y = 0; y < n; y++){
//             if (can_flow_to_pacific[x][y] and can_flow_to_atlantic[x][y]){
//                 answer.push_back({x, y});
//             }
//         }
//     }
//     return answer;
// }

vector<vector<int>> solution1(const vector<vector<int>>& heights){
    const int m = heights.size();
    const int n = heights[0].size();
    vector<vector<int>> can_flow_to_pacific(m, vector<int>(n));
    vector<vector<int>> can_flow_to_atlantic(m, vector<int>(n));
    // can_flow_to_...[x][y] = 0 -> undefined
    // can_flow_to_...[x][y] = -1 -> can not flow
    // can_flow_to_...[x][y] = 1 -> can flow
    auto can_flow = [&](int x_from, int y_from, int x_to, int y_to) -> bool {
        if (x_to < 0 or x_to >= m or y_to < 0 or y_to >= n){
            return false;
        }
        if (can_flow_to_pacific[x_to][y_to] == 2 or can_flow_to_atlantic[x_to][y_to] == 2){
            return false;
        }
        if (heights[x_from][y_from] >= heights[x_to][y_to]){
            return true;
        }
        return false;
    };
    auto dfs_pacific = [&](auto self, int x, int y) -> bool {
        if (can_flow_to_pacific[x][y] == 1 or (x == 0 or y == 0)){
            can_flow_to_pacific[x][y] = 1;
            return true;
        }else if (can_flow_to_pacific[x][y] == -1){
            return false;
        }
        can_flow_to_pacific[x][y] = 2;
        if (can_flow(x, y, x-1, y)){
            if (self(self, x-1, y)){
                can_flow_to_pacific[x][y] = 1;
                return true;
            }
        }
        if (can_flow(x, y, x+1, y)){
            if (self(self, x+1, y)){
                can_flow_to_pacific[x][y] = 1;
                return true;
            }
        }
        if (can_flow(x, y, x, y-1)){
            if (self(self, x, y-1)){
                can_flow_to_pacific[x][y] = 1;
                return true;
            }
        }
        if (can_flow(x, y, x, y+1)){
            if (self(self, x, y+1)){
                can_flow_to_pacific[x][y] = 1;
                return true;
            }
        }
        can_flow_to_pacific[x][y] = -1;
        return false;
    };
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            dfs_pacific(dfs_pacific, x, y);
        }
    }
    auto dfs_atlantic = [&](auto self, int x, int y) -> bool {
        if (can_flow_to_atlantic[x][y] == 1 or (x == m-1 or y == n-1)){
            can_flow_to_atlantic[x][y] = true;
            return true;
        }else if (can_flow_to_atlantic[x][y] == -1){
            return false;
        }
        can_flow_to_atlantic[x][y] = 2;
        if (can_flow(x, y, x-1, y)){
            if (self(self, x-1, y)){
                can_flow_to_atlantic[x][y] = 1;
                return true;
            }
        }
        if (can_flow(x, y, x+1, y)){
            if (self(self, x+1, y)){
                can_flow_to_atlantic[x][y] = 1;
                return true;
            }
        }
        if (can_flow(x, y, x, y-1)){
            if (self(self, x, y-1)){
                can_flow_to_atlantic[x][y] = 1;
                return true;
            }
        }
        if (can_flow(x, y, x, y+1)){
            if (self(self, x, y+1)){
                can_flow_to_atlantic[x][y] = 1;
                return true;
            }
        }
        can_flow_to_atlantic[x][y] = -1;
        return false;
    };
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            dfs_atlantic(dfs_atlantic, x, y);
        }
    }
    vector<vector<int>> answer;
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            if (can_flow_to_pacific[x][y] == 1 and can_flow_to_atlantic[x][y] == 1){
                answer.push_back({x, y});
            }
        }
    }
    return answer;
}


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        return solution1(heights);
    }
};
