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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        queue<pair<TreeNode*,int>> q; 
        if (root) q.push({root, 0});
        int curr_layer = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr.second == curr_layer) {
                ans.push_back(curr.first->val);
                curr_layer++;
            }
            if (curr.first->right) q.push({curr.first->right, curr.second+1});
            if (curr.first->left) q.push({curr.first->left, curr.second+1});
        }
        return ans; 
    }
};
