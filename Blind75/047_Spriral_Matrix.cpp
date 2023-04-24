#include<bits/stdc++.h>

using namespace std;

void rotation(int &delta_x, int &delta_y){
    if (delta_x == 1){
        delta_x = 0;
        delta_y = 1;
    }else if (delta_y == 1){
        delta_x = -1;
        delta_y = 0;
    }else if (delta_x == -1){
        delta_x = 0;
        delta_y = -1;
    }else{
        delta_x = 1;
        delta_y = 0;
    }
}

// 1 <= m, n <= 10
// time: O(m * n)
// extra space: O(1)
// 25:12
vector<int> solve(vector<vector<int>> &matrix){
    const int m = matrix.size();
    const int n = matrix[0].size();
    int x = 0;
    int y = 0;
    int delta_x = 1;
    int delta_y = 0;
    vector<int> answer = {matrix[y][x]};
    const int visited = -101;
    matrix[y][x] = visited;
    while(answer.size() != m * n){
        if ((x + delta_x >= n) or (x + delta_x < 0) or (y + delta_y >= m) or (y + delta_y < 0)){
            rotation(delta_x, delta_y);
        }else if (matrix[y + delta_y][x + delta_x] == visited){
            rotation(delta_x, delta_y);
        }else{
            x += delta_x;
            y += delta_y;
            answer.emplace_back(matrix[y][x]);
            matrix[y][x] = visited;
        }
    }
    return answer;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return solve(matrix);
    }
};