/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copies;
    void dfs(Node* curr) {
        if (copies.count(curr) > 0) return;
        copies[curr] = new Node(curr->val);
        for (auto neighbor: curr->neighbors) {
            dfs(neighbor);
            copies[curr]->neighbors.push_back(copies[neighbor]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        dfs(node);
        return copies[node];
    }
};
