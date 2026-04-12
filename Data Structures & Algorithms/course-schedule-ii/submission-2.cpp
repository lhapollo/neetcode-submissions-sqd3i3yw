class Solution {
public:
    vector<int> ins;
    vector<vector<int>> adj; 

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ins = vector<int>(numCourses, 0);
        adj = vector<vector<int>>(numCourses, vector<int>());
        queue<int> q; 
        vector<int> ans; 
        for (auto edge: prerequisites) {
            ins[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < ins.size(); i++) {
            if (ins[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto n: adj[curr]) {
                ins[n]--;
                if (ins[n] == 0) q.push(n);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};
