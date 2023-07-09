#include<bits/stdc++.h>

using namespace std;

// time: O(n)
// space: O(n)
// time: 07:18
// 参照渡し：pass by reference
void dfs(TreeNode* current_node, const int current_depth, int &maximum_depth){
    maximum_depth = max(maximum_depth, current_depth);
    if (current_node->left) {
        dfs(current_node->left, current_depth+1, maximum_depth);
    }
    if (current_node->right) {
        dfs(current_node->right, current_depth+1, maximum_depth);
    }
}

// int main(){

// }

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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (not root){
            return 0;
        }
        int maximum_depth = 1;
        dfs(root, 1, maximum_depth);
        return maximum_depth;
    }
};