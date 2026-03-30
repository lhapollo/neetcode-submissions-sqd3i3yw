class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; 
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        vector<int> starts; 
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i] - 1) == st.end()) starts.emplace_back(nums[i]);
        }
        int best = 0;
        for (auto i: starts) {
            int start = i; 
            int len = 1;
            if (len > best) best = len; 
            while (true) {
                if (st.find(start + 1) != st.end()) {
                    len++;
                    start++;
                    if (len > best) best = len; 
                } else {
                    break;
                }
            }
        }
        return best; 
    }
};
