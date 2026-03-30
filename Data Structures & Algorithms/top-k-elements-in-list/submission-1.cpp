class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num] = freq[num] + 1;
        }
        vector<vector<int>> counts(nums.size() + 1);
        for (auto i: freq) {
            counts[i.second].emplace_back(i.first); 
        }
        vector<int> ans;
        for (int i = counts.size()-1; i > 0; i--) {
            for (auto j: counts[i]) {
                ans.emplace_back(j);
            }
            if (ans.size() == k) break;
        }
        return ans;
    }
};
