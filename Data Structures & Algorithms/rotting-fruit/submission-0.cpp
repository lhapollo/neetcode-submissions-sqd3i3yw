class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // push all rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (grid[nr][nc] != 1) continue;       // only fresh oranges
                if (dist[nr][nc] != -1) continue;      // already visited

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }

        int ans = 0;

        // compute result
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (dist[i][j] == -1) return -1;
                    ans = max(ans, dist[i][j]);
                }
            }
        }

        return ans;
    }
};