#include<bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTreeTraversal(TreeNode* node1, TreeNode* node2) {
  if (node1 == nullptr and node2 == nullptr) {
    return true;
  }
  if ((node1 == nullptr and node2 != nullptr) or (node1 != nullptr and node2 == nullptr)) {
    return false;
  }

  if (!isSameTreeTraversal(node1->left, node2->left)) {
    return false;
  }
  if (!isSameTreeTraversal(node1->right, node2->right)) {
    return false;
  }

  if (node1->val != node2->val) {
    return false;
  }

  return true;
}

bool isSameTree(TreeNode* root1, TreeNode* root2) {
  return isSameTreeTraversal(root1, root2);
}

bool includeSameSubTree(TreeNode* node, TreeNode* subRoot) {
  if (node == nullptr and subRoot == nullptr) {
    return true;
  }
  if (node == nullptr and subRoot != nullptr) {
    return false;
  }

  if (isSameTree(node, subRoot)) {
    return true;
  }
  if (includeSameSubTree(node->left, subRoot)) {
    return true;
  }
  if (includeSameSubTree(node->right, subRoot)) {
    return true;
  }

  return false;
}

bool solve(TreeNode* root, TreeNode* subRoot) {
  return includeSameSubTree(root, subRoot);
}

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};
