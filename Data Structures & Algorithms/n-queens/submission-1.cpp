class Solution {
public:
    vector<vector<string>> ans; 
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, board);
        return ans;
    }

    void backtrack(int r, vector<string>& board) {
        if (r == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < board.size(); c++ ) {
            if (valid(r, c, board)) {
                board[r][c] = 'Q';
                backtrack(r+1, board);
                board[r][c] = '.';
            }
        }
    }

    bool valid(int r, int c, vector<string>& board) {
        for (int i = r-1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r-1, j = c+1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
