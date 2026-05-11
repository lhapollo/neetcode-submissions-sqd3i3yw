class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for (int num: nums) {
            //if current running sum < 0, we reset it to num
            if (currSum < 0) currSum = 0;
            currSum += num;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
