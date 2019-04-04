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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        pathDFS(root, sum, [], res);
    }

    void pathDFS(TreeNode* root, int sum, vector<int>& out, vector<vector<int>>& res) {
        // if (!root && sum != 0) return;
        // else if (!root && sum == 0) 
        if (!root || sum < 0) return;
        out.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && sum = 0) {
            res.push_back(out);
            return;
        }
        pathDFS(root->left, sum, out, res);
        pathDFS(root->right, sum, out, res);
    }
};