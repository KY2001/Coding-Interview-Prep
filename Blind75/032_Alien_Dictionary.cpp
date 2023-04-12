#include <bits/stdc++.h>

using namespace std;


vector<vector<bool>> get_graph(const vector<string> &words){
    vector<vector<bool>> graph(26, vector<bool>(26));
    for (auto &word: words){
        for (int i = 1; i < word.size(); i++){
            graph[word[i] - 'a'][word[i-1] - 'a'] = true;
        }
    }
    return graph;
}

bool is_independent(int char_idx, vector<vector<bool>> &graph) {
    for (int i = 0; i < 26; i++) {
        if (i == char_idx) continue;
        if (graph[char_idx][i] or graph[i][char_idx]) return false;
    }
    return true;
}

int find_smallest(vector<vector<bool>> &graph){
        for (int i = 0; i < 26; i++){
            bool is_smallest = !(is_independent(i, graph));
            for (int j = 0; j < 26; j++){
                if (graph[i][j]) is_smallest = false;
            }
            if (is_smallest) {
                return i;
            }
        }
        return -1;
}

bool is_empty_graph(vector<vector<bool>> &graph){
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if (graph[i][j]) return false;
        }
    }
    return true;
}

bool contains(const string &str, const char chr){
    for (int i = 0; i < str.size(); i++){
        if (str[i] == chr){
            return true;
        }
    }
    return false;
}

// 1 <= |words| <= 100
// 1 <= |words[i]| <= 100
string solve(const vector<string> &words){
    const string alphabets = "abcdefghijklmnopqrstuvwxyz";
    const int n = words.size();
    vector<vector<bool>> graph = get_graph(words);
    string answer;
    while(1) {
        const int next = find_smallest(graph);
        if (next == -1 and is_empty_graph(graph) and answer.size()) {
            answer = "";
            break;
        } else if (next == -1){
            for (auto alphabet: alphabets) {
                if (!contains(answer, alphabet)){
                    answer += alphabet;
                }
            }
            break;
        } else {
            answer += alphabets[next];
            for (int i = 0; i < 26; i++){
                graph[i][next] = false;
            }
        }
    }
    return answer;
}

class Solution {
public:
    string alienOrder(vector<string>& words) {
        return solve(words);
    }
};
