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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        ListNode* first = head;
        ListNode* second = head;
        while(n > 0) {
            second = second->next;
            n--;
        }
        if(!second) {
            return head->next;
        }
        while(second->next) {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};