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
    bool isValidBST(TreeNode* root) {
        stack<tuple<TreeNode*, long, long>> s;

        s.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while (!s.empty()) {
            //retrieve node
            auto [node, min, max] = s.top();
            s.pop();

            if (node->val < min || node->val > max) return false;

            if (node->right) {
                s.push(make_tuple(node->right, node->val + 1, max));
            }
            if (node->left) {
                s.push(make_tuple(node->left, min, node->val - 1));
            }
        }

        return true;
    }
};
