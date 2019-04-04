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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head;
        ListNode* tmp;
        dummy->next = head;
        int n = 0, shift = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }
        shift = k % n;
        cur = head;
        while (shift > 0) {
            shift--;
            cur = cur->next;
        }
        tmp = cur->next;
        cur->next = NULL;
        dummy->next = tmp;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = head;
        return dummy->next;
    }
};