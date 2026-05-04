class Solution {
public:
    unordered_map<string, int> um; 

    int maxProfit(vector<int>& prices) {
        return dp(0, true, prices);
    }

    int dp(int i, bool buying, vector<int>& prices) { //buying is true if you DO NOT have a stock and can buy a stock, false if you do have a stock. 
        if (i >= prices.size()) return 0;

        string key = to_string(i) + "-" + to_string(buying);
        
        if (um.count(key) > 0) return um[key];

        int dont_buy = dp(i+1, buying, prices); //skip day, don't do anything

        if (buying) {
            int val = dp(i+1, false, prices) - prices[i]; //buy at day i, profit decreases by prices[i]
            um[key] = max(val, dont_buy);
        } else {
            int sell_val = dp(i+2, true, prices) + prices[i]; //sell on day i, SKIP next day (cannot buy)
            um[key] = max(sell_val, dont_buy);
        }

        return um[key];
    } 
};

//dp[i] = maximum profit by the end of day i 