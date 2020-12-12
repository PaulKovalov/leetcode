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

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* l, *r;
        vector<TreeNode*> ancestors(501);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                TreeNode* t = q.front();
                if (i == 0)
                    l = t;
                if (i == k - 1)
                    r = t;
                q.pop();
                if (t->left) {
                    ancestors[t->left->val] = t;
                    q.push(t->left);
                }
                if (t->right) {
                    ancestors[t->right->val] = t;
                    q.push(t->right);
                }
            }
        }
        if (l->val == r->val) {
            return l;
        }
        // otherwise find LCA of l and r
        int left = l->val;
        int right = r->val;
        while (ancestors[left]->val != ancestors[right]->val) {
            left = ancestors[left]->val;
            right = ancestors[right]->val;
        }
        return ancestors[left];
    }
};
