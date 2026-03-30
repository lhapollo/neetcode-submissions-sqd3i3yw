class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& subset, int target, int start) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            if (nums[i] > target) break;

            subset.push_back(nums[i]);
            dfs(ans, nums, subset, target - nums[i], i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;

        sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, subset, target, 0);

        return ans;
    }
};