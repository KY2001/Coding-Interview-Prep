#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// n = number of nodes in the tree
// number of all the pairs is n * (n - 1) / 2 <= 4.5 * 10^8
// word: lowest common ancestor (LCA)

// 28:00
// Time: O(n)
// Space: O(maximum depth of tree = n)

// return maximum path from the node to child leaves
// return max(current_node->val, current_node->val + left_node->val, current_node->val + right_node->val, current_node->val + right_node->val + left_node->val)
int dfs(TreeNode* current_node, TreeNode* parent_node, int& maximum_path_sum) {
  vector<int> child_results;
  if (current_node->left) {
    child_results.push_back(dfs(current_node->left, current_node, maximum_path_sum));
  }
  if (current_node->right) {
    child_results.push_back(dfs(current_node->right, current_node, maximum_path_sum));
  }

  if (child_results.empty()) {
    maximum_path_sum = max(maximum_path_sum, current_node->val);
    return current_node->val;
  }

  const int m = child_results.size();
  for (int i = 0; i < (1 << m); i++) {
    int path_sum = current_node->val;
    for (int j = 0; j < m; j++) {
      if ((i >> j) & 1) {
        path_sum += child_results[j];
      }
    }
    maximum_path_sum = max(maximum_path_sum, path_sum);
  }

  int result = current_node->val;
  for (int i = 0; i < m; i++) {
    result = max(result, current_node->val + child_results[i]);
  }

  return result;
}

int solve(TreeNode* root) {
  int answer = root->val;
  dfs(root, nullptr, answer);

  return answer;
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
      return solve(root);
    }
};
