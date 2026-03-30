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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q; 
        if (root) q.push({root, root->val}); 
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr.second <= curr.first->val) ans++; 
            if (curr.first->left) q.push({curr.first->left, max(curr.first->left->val, curr.second)});
            if (curr.first->right) q.push({curr.first->right, max(curr.first->right->val, curr.second)});
        }
        return ans; 
    }
};
