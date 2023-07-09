#include<bits/stdc++.h>

using namespace std;

void rotation(int &x, int &y, int n){
    const int temp = x;
    x = y;
    y = n - 1 - temp;
}

// time: O(n^2)
// extra space: O(1)
// 29:46
void solve(vector<vector<int>> &matrix){
    const int n = matrix.size();
    const int visited = 3000;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (matrix[x][y] > 1000) continue;
            int x_now = x;
            int y_now = y;
            int next_value = matrix[x][y];
            for (int i = 0; i < 4; i++){
                int x_next = x_now;
                int y_next = y_now;
                rotation(x_next, y_next, n);
                if (x_next == x_now and y_next == y_now){
                    matrix[x][y] += visited;
                    break;
                }
                const int next_value_memo = matrix[x_next][y_next];
                matrix[x_next][y_next] = next_value + visited;
                next_value = next_value_memo;
                x_now = x_next;
                y_now = y_next;
            }
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            matrix[x][y] -= visited;
        }
    }
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        return solve(matrix);        
    }
};
