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
        ListNode* before_start = NULL, *after_end = NULL, *cur = head, *prev = NULL;
        while (m - 1 && cur) {
            --m;
            --n;
            before_start = cur;
            cur = cur->next;
        }
        while (n - 1 && cur) {
            --n;
            cur = cur->next;
        }
        after_end = cur->next;
        if (before_start == NULL) {
            prev = head;
        } else {
            prev = before_start->next;
        }
        cur = prev->next;
        prev->next = after_end;
        while (cur != after_end) {
            ListNode* old_next = cur->next;    
            cur->next = prev;
            prev = cur;
            cur = old_next;
        }
        if (before_start == NULL) {
            head = prev;
        } else {
            before_start->next = prev;
        }
        return head;
    }
};