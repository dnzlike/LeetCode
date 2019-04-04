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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> cur(1, root);
        while (!cur.empty()) {
            vector<int> nums;
            vector<TreeNode*> next;
            for (auto* node : cur) {
                nums.push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right); 
            }
            res.push_back(nums);
            cur = next;
        }
        return res;
    }
};