class Solution {
public:
    vector<vector<bool>> pacific, atlantic;
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<bool>>& vis, int r, int c, vector<vector<int>>& heights) {
        if (vis[r][c]) return;
        vis[r][c] = true;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= heights.size() || nc >= heights[0].size())
                continue;

            if (heights[nr][nc] >= heights[r][c]) {
                dfs(vis, nr, nc, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        atlantic = vector<vector<bool>>(m, vector<bool>(n, false));

        // Pacific
        for (int j = 0; j < n; j++) dfs(pacific, 0, j, heights);
        for (int i = 0; i < m; i++) dfs(pacific, i, 0, heights);

        // Atlantic
        for (int j = 0; j < n; j++) dfs(atlantic, m - 1, j, heights);
        for (int i = 0; i < m; i++) dfs(atlantic, i, n - 1, heights);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};