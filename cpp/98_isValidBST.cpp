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
    bool isValidBST(TreeNode* root) {
        return validDFS(root, LONG_MIN, LONG_MAX);
    }

    bool validDFS(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root->val > min && root->val < max) {
            return validDFS(root->left, min, root->val) && validDFS(root->right, root->val, max);
        }
        else return false;
    } 
};