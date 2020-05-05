/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* list) {
        if (list == NULL || list->next == NULL) {
            return list;
        }
        ListNode *newhead = reverse(list->next);
        list->next->next = list;
        list->next = NULL;
        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        // return reverse(head);
        if (head == NULL) {
            return NULL;
        }
        ListNode *prev = NULL, *i = head;
        while (i != NULL) {
            ListNode *n = i->next;
            i->next = prev;
            prev = i;
            i = n;
        }
        return prev;
    }
};