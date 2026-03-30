class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um; 
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (um.find(comp) != um.end()) {
                return {min(i, um[comp]), max(i, um[comp])};
            } else {
                um[nums[i]] = i;
            }
        }
        return {-1};
    }
};
