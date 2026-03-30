class Solution {
public:
    vector<vector<int>> ans; 
    void rec(vector<int>& nums, vector<int>& curr, int ind) {
        ans.push_back(curr);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            rec(nums, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        rec(nums, curr, 0);
        return ans;
    }
};
