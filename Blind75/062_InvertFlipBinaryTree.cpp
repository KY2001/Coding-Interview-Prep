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

// Time: O(n) where n is the number of node in the tree.
// Space: O(maimum depth of tree)
// 4:56

TreeNode* solve(TreeNode* node) {
  if (!node) {
    return node;
  }
  const auto left_inverted_child = solve(node->left);
  node->left = solve(node->right);
  node->right = left_inverted_child;
  return node;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};
