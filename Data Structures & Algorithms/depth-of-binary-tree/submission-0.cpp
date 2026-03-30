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
    int max_len = 0;
    int maxDepthHelp(TreeNode* root, int len) {
        if (root == nullptr) return max(len, max_len);
        else {
            return max(maxDepthHelp(root->left, len+1), maxDepthHelp(root->right, len+1));
        }
    }

    int maxDepth(TreeNode* root) {
        return maxDepthHelp(root, 0);
    }
};
