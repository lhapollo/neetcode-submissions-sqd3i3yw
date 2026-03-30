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
    int getHeight(TreeNode* root, int len) {
        if (root == nullptr) return len; 
        else return max(getHeight(root->left, len+1), getHeight(root->right, len+1)); 
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true; 
        if (abs(getHeight(root->left, 0) - getHeight(root->right, 0)) > 1) return false; 
        else return (isBalanced(root->left) && isBalanced(root->right));
    }
};
