class Solution {
public:
    vector<vector<int>> memo; 


    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memo = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        return dp(1, nums.size()-2, nums);
    }

    //dp[l][r] -> max coins earned within the interval (l, r)
    int dp(int l, int r, vector<int>& nums) {
        if (l > r) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        memo[l][r] = 0;

        //we are trying every scenario such that the ith balloon is the LAST balloon popped within the (l, r) range. 
        for (int i = l; i <= r; i++) {
            //assuming the current ith is LAST element not popped within (l, r), then we know neighbors MUST be nums[l-1], nums[r+1]
            //we KNOW the coin value we earn since we know the neighbors
            int coins = nums[l-1]*nums[i]*nums[r+1];  
            
            //the coin value in this scenario hinges on the maximum coins earned in the subranges on either side of i
            coins += dp(l, i-1, nums) + dp(i+1, r, nums); 
            
            //update memo based on if ith balloon should be popped last or if better scenario exists already in memo
            memo[l][r] = max(memo[l][r], coins);
        }

        return memo[l][r];
    }
};
