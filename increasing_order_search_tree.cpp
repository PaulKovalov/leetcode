/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* last(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        if (root->right == nullptr)
            return root;
        return last(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        root->right = increasingBST(root->right);
        root->left = increasingBST(root->left);
        if (root->left) {
            TreeNode* newRoot = root->left;
            root->left = nullptr;
            last(newRoot)->right = root;
            return newRoot;
        }
        return root;
    }
};
