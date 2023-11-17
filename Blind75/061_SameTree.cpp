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

// Time: O(min(|p|, |q|)), where |p| or |q| is the number of nodes in each tree.
// Space: O(min(maximum depth of |p| or |q|))

// Time: 11:40


bool isSameTreeDfs(TreeNode* p_child, TreeNode* q_child) {
  if (!p_child and !q_child) {
    return true;
  } else if ((p_child and !q_child) or (!p_child and q_child)) {
    return false;
  }

  if (isSameTreeDfs(p_child->left, q_child->left) and isSameTreeDfs(p_child->right, q_child->right) and p_child->val == q_child->val){
    return true;
  }
  return false;
}

// int main(TreeNode* p, TreeNode* q){
//   return isSameTree(p, q);
// }

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeDfs(p, q);
    }
};
