/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return cloneDFS(node, m);
    }

    Node* cloneDFS(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return NULL;
        if (m.count(node)) return m[node];
        Node* clone = new Node(node->val);
        m[node] = clone;
        for (auto n : node->neighbors) {
            clone->neighbors.push_back(cloneDFS(n, m));
        }
        return clone;
    }
};