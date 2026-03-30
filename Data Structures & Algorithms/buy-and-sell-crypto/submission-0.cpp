class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int ans = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                ans = max(ans, prices[r] - prices[l]);
            } else {
                l = r; //if prices[l] >= prices[r], we set l = r (we found a cheaper buy price) 
            }
            r++;
        }
        return ans;
    }
};
