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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        TreeNode* node = root;

        while (!lca) {
            if (p->val < node->val && q->val < node->val) {
                //left subtree
                node = node->left;
            } else if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else {
                lca = node;
            }
        }

        return node;
    }
};
