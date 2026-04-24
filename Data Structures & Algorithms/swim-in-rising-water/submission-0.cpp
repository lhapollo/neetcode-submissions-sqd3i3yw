class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<pair<int, int>> vis; 
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap; 

        minHeap.push({grid[0][0], 0, 0});
        vis.insert({0, 0});

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();

            int t = curr[0], r = curr[1], c = curr[2];

            if (r == N-1 && c == N-1) return t;

            for (auto nei: dirs) {
                int nr = r + nei.first;
                int nc = c + nei.second;

                if (nr < 0 || nc < 0 || nr >= N || nc >= N || vis.count({nr, nc})) continue;

                vis.insert({nr, nc});
                minHeap.push({max(t, grid[nr][nc]), nr, nc});

            }
        }

        return -1;
    }
};
