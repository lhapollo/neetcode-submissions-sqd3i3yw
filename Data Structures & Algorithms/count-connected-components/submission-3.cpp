class Solution {
public:
    vector<int> parent; 
    vector<int> size;

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return false; // already connected

        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n);
        size = vector<int>(n);

        for (int i = 0; i < n; i++) {
            make_set(i);
        }

        int components = n;

        for (auto& edge : edges) {
            if (union_sets(edge[0], edge[1])) {
                components--; // only decrement if union happened
            }
        }

        return components;
    }
};