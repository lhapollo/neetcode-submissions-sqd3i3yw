class Solution {
public:
    vector<int> parent, size;

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]); // path compression
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b); // union by size
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // init DSU
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        // build edges: {weight, u, v}
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        // sort edges by weight
        sort(edges.begin(), edges.end());

        int cost = 0, cnt = 0;

        for (auto& e : edges) {
            int w = e[0], u = e[1], v = e[2];
            if (unite(u, v)) {
                cost += w;
                if (++cnt == n - 1) break;
            }
        }

        return cost;
    }
};