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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
           ListNode *res, *head;
        if (l1 == nullptr) {
           return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else {
            if (l1->val < l2->val) {
                res = new ListNode(l1->val);
                l1 = l1->next;
            }  else {
                res = new ListNode(l2->val);
                l2 = l2->next;
            }
        }
        head = res;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                res->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                res->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            res = res->next;
        }
        while (l1 != nullptr) {
            res->next = new ListNode(l1->val);
            res = res->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            res->next = new ListNode(l2->val);
            res = res->next;
            l2 = l2->next;
        }
        return head;
        
    }
};