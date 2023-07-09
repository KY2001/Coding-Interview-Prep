using namespace std;

// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

void dfs(Node *node, Node *copied, map<int, Node*> &done){
    if (node == nullptr) {
        return;
    }
    done[node->val] = copied;

    const int n = node->neighbors.size();
    copied->val = node->val;
    for (int i = 0; i < n; i++){
        if (done.count(node->neighbors[i]->val)){
            copied->neighbors.push_back(done[node->neighbors[i]->val]);
        }else{
            copied->neighbors.push_back(new Node());
            dfs(node->neighbors[i], copied->neighbors[i], done);
        }
    }
}

Node* solution1(Node* node){
    if (node == nullptr) {
        return nullptr; // NULLでも動作する。nullは☓。
    }
    map<int, Node*> done;
    Node *answer = new Node();
    dfs(node, answer, done);
    return answer;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return solution1(node);
  }
};
