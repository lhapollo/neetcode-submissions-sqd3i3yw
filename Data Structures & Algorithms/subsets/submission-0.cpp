class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> subset; 
        rec(nums, 0, subset, ans);
        return ans; 
    }

    void rec(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        rec(nums, i+1, subset, res);
        subset.pop_back();
        rec(nums, i+1, subset, res);
    }
};
