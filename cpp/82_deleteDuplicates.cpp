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
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* ppre = dummy;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
            while (cur && cur->val == pre->val) {
                n++;
                cur = cur->next;
            }
            if (n == 1) {
                ppre->next = new ListNode(pre->val);
                ppre = ppre->next;
            }
            pre = cur;
            n = 0;
        }
        return dummy->next;
    }
};