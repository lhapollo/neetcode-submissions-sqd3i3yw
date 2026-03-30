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
    int cnt = -1;
    int ans = -1;

    void dfs(TreeNode* root) {
        if (!root) return; 
        dfs(root->left);
        cnt--; 
        if (cnt == 0) {
            ans = root->val;
            return; 
        }   
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        dfs(root);
        return ans; 
    }
};
