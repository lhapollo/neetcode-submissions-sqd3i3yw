class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj; 
        vector<int> dist(n+1, INT_MAX);
        
        for (auto time: times) {
            adj[time[0]].push_back({time[1], time[2]}); 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

        dist[k] = 0;
        pq.push({0, k}); 
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int distance = top.first;
            int node = top.second;

            if (distance > dist[node]) continue; 

            for (auto neighbor: adj[node]) {
                int v = neighbor.first;
                int d = neighbor.second;

                if (dist[v] > distance + d) {
                    dist[v] = distance + d;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = -1; 
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};