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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = dummy;
        for (int i = 0; i < (n - m + 1); i++) {
            right = right->next;
        }
        for (int i = 0; i < (m - 1); i++) {
            left = left->next;
            right = right->next;
        }
        for (int i = 0; i < (n - m); i++) {
            ListNode* tmp = left->next;
            left->next = left->next->next;
            tmp->next = right->next;
            right->next = tmp;
        }
        return dummy->next;
    }
};