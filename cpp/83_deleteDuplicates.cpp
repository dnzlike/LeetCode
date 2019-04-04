/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = head;
        while (cur) {
            cur = cur->next;
            while (cur && cur->val == pre->val) {
                cur = cur->next;
            }
            pre->next = cur;
            pre = cur;
        }
        return head;
    }
};