class Solution {
public:
    vector<vector<int>> ans; 
    vector<vector<int>> permute(vector<int>& nums) {
        rec(0, nums);
        return ans; 
    }

    void rec(int idx, vector<int>& nums) {
        //base case
        if (idx == nums.size()) {
            ans.push_back(nums);
            return; 
        }
        //iterate
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            rec(idx+1, nums);
            swap(nums[idx], nums[i]);
        }
    }
};
