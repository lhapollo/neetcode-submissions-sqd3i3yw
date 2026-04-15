class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adj;

    bool validTree(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, 0);
        adj = vector<vector<int>>(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // check cycle
        if (!dfs(0, -1)) return false;

        // check connected
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) return false;
        }

        return true;
    }

    bool dfs(int curr, int parent) {
        visited[curr] = true;

        for (auto nei : adj[curr]) {
            if (nei == parent) continue;

            if (visited[nei]) return false; // must be a back edge = cycle

            if (!dfs(nei, curr)) return false;
        }

        return true;
    }
};