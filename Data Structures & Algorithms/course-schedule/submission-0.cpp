class Solution {
public:
    vector<vector<int>> adj;
    vector<int> state; // 0 = unvisited, 1 = visiting, 2 = visited

    bool dfs(int curr) {
        if (state[curr] == 1) return false; // cycle
        if (state[curr] == 2) return true;  // already processed

        state[curr] = 1; // mark as visiting

        for (int next : adj[curr]) {
            if (!dfs(next)) return false;
        }

        state[curr] = 2; // mark as done
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        state = vector<int>(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }

        return true;
    }
};