class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        } 

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if ((i != 0 && j != 0) || (i == 0 && j == 0)) continue; 
                    int r_dir = curr[0] + i;
                    int c_dir = curr[1] + j;
                    if (r_dir < 0 || c_dir < 0 || r_dir >= grid.size() || c_dir >= grid[0].size()) continue;
                    if (grid[r_dir][c_dir] != INT_MAX) continue;
                    grid[r_dir][c_dir] = grid[curr[0]][curr[1]] + 1;
                    q.push({r_dir, c_dir});
                }
            }
        }
    }
};
