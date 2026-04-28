class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        vector<int> memo(amount + 5, INT_MAX);
        memo[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && memo[i-coins[j]] != INT_MAX) memo[i] = min(memo[i], 1 + memo[i - coins[j]]); 
            }
        }        
        return memo[amount] == INT_MAX? -1 : memo[amount];
    }
};
