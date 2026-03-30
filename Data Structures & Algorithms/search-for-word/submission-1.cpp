class Solution {
public:
    vector<vector<bool>> vis; 
    bool found = false; 
    void dfs(vector<vector<char>>& board, int r, int c, string curr, string word) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (vis[r][c]) return;  
        vis[r][c] = true; 
        curr += board[r][c];
        if (curr.back() != word[curr.size() - 1]) {
            vis[r][c] = false;
            return;
        }
        if (curr.length() == word.length()) {
            if (curr == word) found = true; 
            return; 
        }
        dfs(board, r+1, c, curr, word);
        dfs(board, r-1, c, curr, word);
        dfs(board, r, c-1, curr, word);
        dfs(board, r, c+1, curr, word);
        vis[r][c] = false;
        curr.pop_back();
    }
    bool exist(vector<vector<char>>& board, string word) {
        vis = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, "", word);
            }
        }
        return found; 
    }
};
