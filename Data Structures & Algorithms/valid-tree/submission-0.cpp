class Solution {
public:
    vector<int> states;
    vector<vector<int>> adj;

    bool validTree(int n, vector<vector<int>>& edges) {
        states = vector<int>(n, 0);
        adj = vector<vector<int>>(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // check cycle
        if (!dfs(0, -1)) return false;

        // check connected
        for (int i = 0; i < n; i++) {
            if (states[i] == 0) return false;
        }

        return true;
    }

    bool dfs(int curr, int parent) {
        states[curr] = 1;

        for (auto nei : adj[curr]) {
            if (nei == parent) continue; // skip parent

            if (states[nei] == 1) return false; // cycle

            if (!dfs(nei, curr)) return false;
        }

        states[curr] = 2;
        return true;
    }
};