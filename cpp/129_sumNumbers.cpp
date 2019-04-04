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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        vector<TreeNode*> res(1, root);
        int ret;
        while (!res.empty()) {
            vector<TreeNode*> tmp;
            for (TreeNode* node : res) {
                if (node->left) {
                    node->left->val += 10 * node->val;
                    tmp.push_back(node->left);
                }
                if (node->right) {
                    node->right->val += 10 * node->val;
                    tmp.push_back(node->right);
                }
                if (!node->left && !node->right) {
                    ret += node->val;
                }
            }
            res = tmp;
        }
        return ret;
    }

};