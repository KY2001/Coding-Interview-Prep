#include<bits/stdc++.h>
using namespace std;

bool dfs(const int index, const int x, const int y, const vector<vector<char>> &board_with_space, const string &word, vector<vector<bool>> &visited){
    // board_with_space[x][y]
    if (visited[x][y]) return false;
    if (board_with_space[x][y] != word[index] or board_with_space[x][y] == '-'){
        return false;
    }
    if (index == word.size()-1){
        return true;
    }
    visited[x][y] = true;
    if (dfs(index+1, x+1, y, board_with_space, word, visited)){
        return true;
    }
    if (dfs(index+1, x-1, y, board_with_space, word, visited)){
        return true;
    }
    if (dfs(index+1, x, y+1, board_with_space, word, visited)){
        return true;
    }
    if (dfs(index+1, x, y-1, board_with_space, word, visited)){
        return true;
    }
    visited[x][y] = false;
    return false;
}

// m = board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// time: 20:00
// time complexity: O(?)
// space complexity: O(m * n)
bool solve(const vector<vector<char>> &board, const string &word){
    const int m = board.size();
    const int n = board[0].size();
    vector<vector<char>> board_with_space(m+2, vector<char>(n+2, '-'));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            board_with_space[i+1][j+1] = board[i][j];
        }
    }
    vector<vector<bool>> visited(m+2, vector<bool>(n+2));
    for (int i = 1; i < m+1;i++){
        for (int j = 1; j < n+1; j++){
            if (dfs(0, i, j, board_with_space, word, visited)){
                return true;
            }
        }
    }
    return false;
}

// int main(){
// }

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return solve(board, word);
    }
};
