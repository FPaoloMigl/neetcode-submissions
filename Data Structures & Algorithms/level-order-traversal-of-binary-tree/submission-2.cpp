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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (!root) return {};
        int level = 0;

        //move this inside while 
        // vector<vector<int>> res = {
        //     {root->val}
        // };
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        //insert children
        // q.push(root->left);
        // q.push(root->right);
        q.push(root);

        while(!q.empty()){
            auto node = q.front();

            if (!node) {
                q.pop();
                continue;
            }

            res.push_back({});

            // auto node = q.front();

            // if (node) res.push_back({}); 

            int size = q.size();

            for(int i = 0; i<size; ++i) {
                //retrieve the node
                node = q.front();
                q.pop();

                if (!node) continue;
                
                res[level].push_back(node->val); 

                q.push(node->left);
                q.push(node->right);
            }
            level++;
        }
        return res;
        
    }
};
