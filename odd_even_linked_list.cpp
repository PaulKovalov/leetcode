#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *cur = head, *odd_branch = NULL, *even_branch = NULL, *curnext = NULL;
        odd_branch = head;
        even_branch = odd_branch->next;
        while (cur->next != NULL) {
            curnext = cur->next;
            // do smth here
            cur->next = cur->next->next;
            cur = curnext;
        }
        ListNode *odd_branch_tail = odd_branch;
        while (odd_branch_tail->next) {
            odd_branch_tail =  odd_branch_tail->next;
        }
        odd_branch_tail->next = even_branch;
        for (ListNode *i = odd_branch; i != NULL; i = i->next) {
            cout << i->val << " ";
        }
        cout << endl;
        return NULL;
    }
    
};

int main() {
    Solution solution;
    ListNode* ll = new ListNode(1, new ListNode(2, new ListNode(3)));
    solution.oddEvenList(ll);
    return 0;
}