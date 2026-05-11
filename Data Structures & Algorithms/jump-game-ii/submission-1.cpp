class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        while (r < nums.size()-1) {
            int best_dist = -1;
            int curr_dist = 0;
            for (int i = l; i <= r; i++) {
                curr_dist = i + nums[i];
                best_dist = max(best_dist, curr_dist);
            }
            cnt++;
            l = r+1;
            r = best_dist;
        }
        return cnt;
    }
};
