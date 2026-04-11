class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') return; 
        board[r][c] = 'T'; 
        dfs(r-1, c, board);
        dfs(r+1, c, board);
        dfs(r, c+1, board);
        dfs(r, c-1, board);
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][board[0].size()-1] == 'O') dfs(i, board[0].size() -1, board);
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[board.size()-1][j] == 'O') dfs(board.size()-1, j, board);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'T') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
