class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1; 
            int k = nums.size()-1;
            int target = -nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k]; 
                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // skip duplicate j
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // skip duplicate k
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
