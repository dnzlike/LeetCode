/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        balanceDFS(root, res);
        return res;
    }

    int balanceDFS(TreeNode* root, bool& res) {
        if (!root) return 0;
        int left = balanceDFS(root->left, res);
        int right = balanceDFS(root->right, res);
        if (abs(left - right) > 1) res = false;
        return 1 + max(left, right);
    }
};