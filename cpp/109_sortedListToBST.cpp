/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return generateTree(head, NULL);
    }

    TreeNode* generateTree(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;
        ListNode *fast = head, *slow = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = generateTree(head, slow);
        root->right = generateTree(slow->next, tail);
        return root;
    }
};