class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        for (int i = nums.size()-1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }         
            }
        }
        int ans = 1;
        for (auto i: lis) {
            ans = max(ans, i);
        }
        return ans;
    }
};
