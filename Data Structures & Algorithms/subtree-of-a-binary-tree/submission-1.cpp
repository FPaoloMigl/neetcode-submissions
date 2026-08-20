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

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        stack<pair<TreeNode*, TreeNode*>> s;

        s.push({root, subRoot});

        while(!s.empty()) {
            // retrieve the node
            auto [node1, node2] = s.top();
            s.pop();

            if (!node1 && !node2) continue; // this can be deleted

            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }
            
            s.push({node1->right, node2->right});
            s.push({node1->left, node2->left});
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        bool res = false;
        q.push(root);

        while (!q.empty()){
            auto node = q.front();
            q.pop();

            if (!node) continue;

            if (node && node->val == subRoot->val && sameTree(node, subRoot)) {
                return true;
            }

            q.push(node->right);
            q.push(node->left);
        }

        return res;
    }
};
