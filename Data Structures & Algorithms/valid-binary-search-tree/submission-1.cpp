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
    bool help(TreeNode* root, int min_val, int max_val) {
        if (!root) return true; 
        if (root->val >= max_val || root->val <= min_val) return false; 
        return help(root->left, min_val, root->val) && help(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return help(root, -2000, 2000);
    }
};
