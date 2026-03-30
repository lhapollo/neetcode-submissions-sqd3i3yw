class Codec {
public:
    void dfs(TreeNode* root, string& ans) {
        if (!root) {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans;
        dfs(root, ans);
        return ans;
    }

    TreeNode* dfs(vector<string> nodes, int& ind) {
        if (nodes[ind] == "N") {
            ind++;
            return nullptr; 
        }
        TreeNode* node = new TreeNode(stoi(nodes[ind]));
        ind++;
        node->left = dfs(nodes, ind);
        node->right = dfs(nodes, ind);
        return node;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes; 
        string curr; 
        for (char c: data) {
            if (c == ',') {
                nodes.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        int i = 0;
        return dfs(nodes, i);
    }
};