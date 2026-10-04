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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* parent = nullptr, *curr = root; 
        if (!root) return new TreeNode(val);
        while (curr) {
            parent = curr;
            if (val < curr->val) {
                //go left
                curr = curr->left; 
            } else {
                //go right - guaranteed val != curr->val
                curr = curr->right; 
            }
        }
        curr = new TreeNode(val); 
        if (val < parent->val) parent->left = curr; 
        else parent->right = curr; 
        return root; 
    }
};