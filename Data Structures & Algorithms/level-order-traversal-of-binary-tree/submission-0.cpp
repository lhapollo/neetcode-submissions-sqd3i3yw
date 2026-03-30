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
        vector<vector<int>> ans; 
        queue<pair<TreeNode*, int>> q; 
        if (root) q.push({root, 0}); 
        while (!q.empty()) {
            auto curr= q.front();
            q.pop();
            int lvl = curr.second; 
            if (ans.size() == lvl) {
                ans.push_back({});
            }
            ans[lvl].push_back(curr.first->val);
            if (curr.first->left) q.push({curr.first->left, lvl+1});
            if (curr.first->right) q.push({curr.first->right, lvl+1});
        }
        return ans; 
    }
};
