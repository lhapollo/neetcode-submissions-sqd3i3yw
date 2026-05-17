class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans; 
        int ind = 0;
        int n = intervals.size();
        
        //intervals end before new interval starts
        while (ind < n && intervals[ind][1] < newInterval[0]) {
            ans.push_back(intervals[ind]);
            ind++;
        }

        //intervals have some overlap with new interval
        while (ind < n && (newInterval[1] >= intervals[ind][0])) {
            newInterval[0] = min(newInterval[0], intervals[ind][0]);
            newInterval[1] = max(newInterval[1], intervals[ind][1]);
            ind++;
        }

        ans.push_back(newInterval);

        //intervals start after new interval
        while (ind < n) {
            ans.push_back(intervals[ind]);
            ind++;
        } 

        return ans;
    }
};
