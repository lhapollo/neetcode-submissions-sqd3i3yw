class Solution {
public:
    bool isValid(vector<char> task) {
        unordered_set<char> s;
        for (int i = 0; i < task.size(); i++) {
            if (s.find(task[i]) != s.end()) return false; 
            if (task[i] != '.') s.insert(task[i]);
        }
        return true; 
    }

    bool isValidBox(vector<vector<char>>& board, int tx, int ty) {
        vector<char> box; 
        for (int i = tx; i <= tx + 2; i++) {
            for (int j = ty; j <= ty + 2; j++) {
                box.emplace_back(board[i][j]);
            }
        }
        return isValid(box);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //check all rows
        for (int i = 0; i < 9; i++) {
            if (!isValid(board[i])) return false;
        }
        //check all cols
        for (int i = 0; i < 9; i++) {
            vector<char> col; 
            for (int j = 0; j < 9; j++) {
                col.emplace_back(board[j][i]);
            }
            if (!isValid(col)) return false; 
        }
        //check all boxes
        for (int i = 0; i <= 6; i += 3) {
            for (int j = 0; j <= 6; j+= 3) {
                if (!isValidBox(board, i, j)) return false;
            }
        }
        return true;
    }
};
