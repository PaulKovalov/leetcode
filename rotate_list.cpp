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
        // get the length of the list
        if (head == NULL) {
            return head;
        }
        int l = 0;
        for (ListNode* cur = head; cur != NULL; cur = cur->next) {
            ++l;
        }
        k = k % l;
        if (k) {
        int i = 0;
        for (ListNode* cur = head; cur != NULL; cur = cur->next) {
            ++i;
            if (l - i == k) {
                ListNode* tail = cur->next;
                cur->next = NULL;
                for (ListNode* n = tail; n != NULL; n = n->next) {
                    if (n->next == NULL) {
                        n->next = head;
                        return tail;
                    }
                }
            }
        }
        }
        return head;
    }
};