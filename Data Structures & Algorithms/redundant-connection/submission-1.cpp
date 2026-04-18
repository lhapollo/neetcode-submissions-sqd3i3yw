class Solution {
public:
    vector<int> parent;
    vector<int> size; 

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_parent(int v) {
        if (v == parent[v]) return v;
        else return parent[v] = find_parent(parent[v]);
    }

    //returns true if successfully merged two sets
    bool union_set(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);

        if (a == b) return false; 

        if (size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
        return true;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent = vector<int>(n+1);
        size = vector<int>(n+1, 0);

        for (int i = 1; i <= n; i++) {
            make_set(i);
        }

        for (auto edge: edges) {
            bool is_valid = union_set(edge[0], edge[1]); 
            if (!is_valid) return edge; 
        }

        return {-1};
    }
};
