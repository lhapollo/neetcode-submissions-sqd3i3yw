class Solution {
public:
    int dfs(vector<vector<int>>& grid, int size, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, size, r+1, c) + dfs(grid, size, r-1, c) + dfs(grid, size, r, c+1) + dfs(grid, size, r, c-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int curr = 0;
                if (grid[i][j] == 1) {
                    curr = dfs(grid, curr, i, j);
                    ans = max(ans, curr);
                }
            }
        }    
        return ans;
    }
};
