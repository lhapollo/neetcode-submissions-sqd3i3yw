class Solution {
   public:
    vector<vector<int>> memo;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                dp(i, j, matrix);
            }
        }

        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, memo[i][j]);
            }
        }
        return ans;
    }

    int dp(int i, int j, vector<vector<int>>& matrix) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        int res = 1;

        for (auto& [x, y] : dirs) {
            int nx = x + i;
            int ny = y + j;

            if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()) continue;

            if (matrix[i][j] < matrix[nx][ny]) {
                res = max(res, 1 + dp(nx, ny, matrix));
            }
        }

        memo[i][j] = res;
        return res;
    }
};

// memo[i][j] = longest increasing path starting from (i, j)