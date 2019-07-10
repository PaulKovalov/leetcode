/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int integer = 0;
        ListNode* root = NULL;
        ListNode* current = NULL;
        while(l1 != NULL || l2 != NULL) {
            if (root == NULL) {
                integer = l1->val + l2->val;
                carry = integer/10;
                root = new ListNode(integer%10);
                std::cout << integer%10 << std::endl;
                current = root;
            } else {
                if (l1 != NULL) {
                    integer += l1->val;
                }
                if (l2 != NULL) {
                    integer += l2->val;
                }
                integer += carry;
                std::cout << integer%10 << std::endl;
                root->next = new ListNode(integer%10);
                root = root->next;
                carry = integer/10;
            }
            integer = 0;
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        } 
        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            root->next = node;
        }
        return current;
    }
};