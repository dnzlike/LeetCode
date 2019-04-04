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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        dummy->next = head;
        ListNode* tmp;
        while(cur->next && cur->next->next) {
            tmp = cur->next->next;
            cur->next->next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        return dummy->next;
    }
};