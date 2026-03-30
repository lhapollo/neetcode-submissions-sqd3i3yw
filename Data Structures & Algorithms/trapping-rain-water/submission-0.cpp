class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix, suffix;
        int curr = 0; 
        for (int i = 0; i < height.size(); i++) {
            curr = max(curr, height[i]);
            prefix.emplace_back(curr);
        }
        curr = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            curr = max(curr, height[i]);
            suffix.emplace_back(curr);
        }
        reverse(suffix.begin(), suffix.end());
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            ans += (min(prefix[i], suffix[i]) - height[i]);
        }
        return ans;
    }
};
