#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


int main() {
    Node* head = new Node(10);
    head->left = new Node(5);
    head->right = new Node(15);
    head->left->left = new Node(1);
    head->left->right = new Node(7);
    head->right->left = new Node(12);
    head->right->right = new Node(20);

    Node* next_level_start = nullptr;
    Node* next_level_iter = nullptr;
    Node* cur = 
    return 0;
}
