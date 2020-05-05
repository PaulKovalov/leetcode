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
    void swapNodes(ListNode* prev, ListNode* first, ListNode *second) {        
        first->next = second->next;
        second->next = first;
        if (prev != nullptr) {
            prev->next = second;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        // int count = 0;
        ListNode* prev = nullptr;
        ListNode* newHead = head;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (newHead == head && curr->next != nullptr) {
                newHead = curr->next;
            }
            ListNode *tmp = curr->next;
            if (tmp != nullptr) {
                curr->next = curr->next->next;
                tmp->next = curr;
                if (prev != nullptr) {
                    prev->next = tmp;
                }
                prev = curr;
                curr = curr->next;
            } else {
                return newHead;
            }
        }
        return newHead;
    }
};