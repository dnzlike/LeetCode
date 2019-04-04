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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* cur = new TreeNode(-1);
        for (int i = preorder.size() - 1; i >= 0; i--) {
            if (preorder[i] == inorder[i]) {
                cur->val = preorder[i];
                continue;
            }
            TreeNode* root = new TreeNode(inorder[i]);
            TreeNode* left = new TreeNode(preorder[i]);
            root->left = left;
            root->right = cur;
            cur = root;
            i--;
        }
        return cur;
    }
};