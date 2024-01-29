#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void dfs(TreeNode* current, const int depth, vector<vector<int>>& answer) {
  if (current == nullptr) {
    return;
  }

  if (answer.size() < depth + 1) {
    answer.push_back({});
  }
  answer[depth].push_back(current->val);

  dfs(current->left, depth+1, answer);
  dfs(current->right, depth+1, answer);
}


vector<vector<int>> solve(TreeNode* root) {
  vector<vector<int>> answer;

  dfs(root, 0, answer);

  return answer;
}
