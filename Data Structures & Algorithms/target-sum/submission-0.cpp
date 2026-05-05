class Solution {
public:
    vector<vector<int>> memo;
    int totalSum; 

    int findTargetSumWays(vector<int>& nums, int target) {
        //need 2*totalSum space in memo (range is [-totalSum, totalSum])
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        memo = vector<vector<int>> (nums.size(), vector<int>(2*totalSum + 5, INT_MIN));
        return dp(0, 0, target, nums);
    }

    int dp(int i, int total, int target, vector<int>& nums) {
        if (i >= nums.size()) {
            return total == target;
        }

        if (memo[i][total + totalSum] != INT_MIN) { //total+totalSum maps [-totalSum, totalSum] to [0, 2 * totalSum + 1]
            return memo[i][total+totalSum];
        }

        memo[i][total+totalSum] = dp(i+1, total + nums[i], target, nums) + dp(i+1, total - nums[i], target, nums);

        return memo[i][total+totalSum];
    }
};
