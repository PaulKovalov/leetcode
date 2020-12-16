/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(vector<int>& ans, TreeNode* node) {
        if (node != nullptr) {
            inorder(ans, node->left);
            ans.push_back(node->val);
            inorder(ans, node->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    typedef long long ull;

    bool helper(TreeNode* root, ull l, ull r) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= l || root->val >= r) {
            return false;
        }
        return helper(root->right, root->val, r) && helper(root->left, l, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, numeric_limits<ull>::min(), numeric_limits<ull>::max());
    }
};
