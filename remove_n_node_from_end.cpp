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
        ListNode* to_remove_prev = nullptr;
        ListNode* to_remove = head;
        int c = 0;
        for (ListNode* i = head; i != nullptr; i = i->next) {
            ++c;
            if (c > n) {
                to_remove_prev = to_remove;
                to_remove = to_remove->next;
            }
        }
        if (c == n) {
            head = head->next;
        } else {
            to_remove_prev->next = to_remove->next;
        }
        return head;
    }
};