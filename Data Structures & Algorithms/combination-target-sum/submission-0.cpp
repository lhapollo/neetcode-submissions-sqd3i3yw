class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& subset, int index, int target) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (nums[i] > target) continue;

            subset.push_back(nums[i]);
            dfs(ans, nums, subset, i, target - nums[i]); // reuse same number
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(ans, nums, subset, 0, target);
        return ans;
    }
};