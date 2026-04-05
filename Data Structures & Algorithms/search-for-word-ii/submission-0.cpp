class Solution {
public:
    struct TrieNode {
        bool end_word = false; 
        unordered_map<char, TrieNode*> um; 
    };

    TrieNode* root = new TrieNode();
    TrieNode* curr = root;

    void insert(string word) {
        curr = root; 
        for (int i = 0; i < word.length(); i++) {
            if (curr->um.count(word[i]) == 0) {
                curr->um[word[i]] = new TrieNode();
            } 
            curr = curr->um[word[i]];
        }
        curr->end_word = true;
    }

    bool search(string word) {
        curr = root; 
        for (int i = 0; i < word.length(); i++) {
            if (curr->um.count(word[i]) == 0) return false; 
            curr = curr->um[word[i]];
        }
        return curr->end_word; 
    }

    vector<string> ans; 

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& used, TrieNode* node, string& curr, int r, int c) {
        
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || used[r][c]) return;

        char ch = board[r][c];
        if (node->um.count(ch) == 0) return;  // 🔥 prefix pruning

        node = node->um[ch];
        curr += ch;

        if (node->end_word) {
            ans.push_back(curr);
            node->end_word = false; // avoid duplicates
        }

        used[r][c] = true;

        dfs(board, used, node, curr, r+1, c);
        dfs(board, used, node, curr, r-1, c);
        dfs(board, used, node, curr, r, c+1);
        dfs(board, used, node, curr, r, c-1);

        used[r][c] = false;
        curr.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (auto word: words) {
            insert(word);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string curr = "";
                dfs(board, used, root, curr, i, j);
            }
        }
        return ans; 
    }
};
