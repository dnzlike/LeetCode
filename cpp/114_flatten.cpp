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
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* cur = root->left;
        if (!cur) return;
        while(cur->right) {cur = cur->right;}
        cur->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};