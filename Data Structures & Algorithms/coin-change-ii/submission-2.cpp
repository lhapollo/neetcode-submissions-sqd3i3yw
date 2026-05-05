class Solution {
public:
    vector<vector<int>> memo; 

    int change(int amount, vector<int>& coins) {
        memo = vector<vector<int>>(coins.size() + 1, vector<int>(amount+1, -1));     
        return dp(0, amount, coins);
    }

    //dp[i][a] = how many ways to make amount a using coins from index i and beyond

    int dp(int i, int a, vector<int>& coins) {
        if (a == 0) return 1; //one way to make 0 dollars
        if (i >= coins.size()) return 0;
        if (memo[i][a] != -1) return memo[i][a];

        int res = dp(i + 1, a, coins); // skip coin

        if (a >= coins[i]) {
            res += dp(i, a - coins[i], coins); //if we use current coin
        }

        memo[i][a] = res;
        return res;
    }
};