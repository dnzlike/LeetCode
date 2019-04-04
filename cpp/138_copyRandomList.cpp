/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        copyDFS(head, m);
    }

    Node* copyDFS(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return NULL;
        if (m.count[node]) return m[node];
        Node* copy = new Node(node->val);
        m[node] = copy;
        copy->next = copy(node->next);
        copy->random = copy(node->random);
        return copy;
    }
};