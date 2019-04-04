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
    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) return true;
        else if (!root->left || !root->right) return false;
        else return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q) return false;
        else return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left); 
    }
};