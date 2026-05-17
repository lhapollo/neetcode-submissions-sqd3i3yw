class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int prev_end = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (prev_end > intervals[i][0]) {
                prev_end = min(prev_end, intervals[i][1]);
                ans++;
            } else {
                prev_end = intervals[i][1];
            }
        }
        return ans;
    }
};
