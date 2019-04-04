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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        while(n > 1) {
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1), *cur = res;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if(l1) {
            cur->next = l1;
        }
        if(l2) {
            cur->next = l2;
        }
        return res->next;
    }
};

struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
 
class Solution {  
public:  
    ListNode *mergeKLists(vector<ListNode *> &lists) {  
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) q.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) q.push(tmp->next);
        }
        return head;
    }  
};