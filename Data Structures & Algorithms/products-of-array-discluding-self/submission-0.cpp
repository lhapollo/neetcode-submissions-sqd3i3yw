class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lhs, rhs;
        int curr = 1;
        for (int i = 0; i < nums.size(); i++) {
            curr *= nums[i];
            lhs.emplace_back(curr);
        }
        curr = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            curr *= nums[i];
            rhs.emplace_back(curr);
        }
        reverse(rhs.begin(), rhs.end());
        vector<int> ans;
        // for (auto i: lhs) cout << i << " ";
        // cout << endl;
        // for (auto i: rhs) cout << i << " ";
        // cout << endl;
        for (int i = 0; i < nums.size(); i++) {
            int lh = (i - 1 < 0 ? 1 :lhs[i-1]);
            int rh = (i + 1 >= nums.size() ? 1 : rhs[i+1]);
            ans.push_back(lh * rh);
        }
        return ans;
    }
};
