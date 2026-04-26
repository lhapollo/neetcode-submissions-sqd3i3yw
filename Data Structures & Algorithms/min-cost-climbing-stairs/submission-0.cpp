class Solution {
public:
    vector<int> memo = vector<int>(110, -1);

    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int> cost, int i) {
        if (i >= cost.size()) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = cost[i] + min(dfs(cost, i+1), dfs(cost, i+2));
    }
};
