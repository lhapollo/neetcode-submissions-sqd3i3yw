class Solution {
public:
    int curr = 0;
    unordered_map<int, int> um;

    TreeNode* dfs(int l, int r, vector<int>& preorder) {
        if (l > r) return nullptr;

        int rootVal = preorder[curr++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = um[rootVal];

        root->left = dfs(l, mid - 1, preorder);
        root->right = dfs(mid + 1, r, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            um[inorder[i]] = i;
        }

        return dfs(0, inorder.size() - 1, preorder);
    }
};