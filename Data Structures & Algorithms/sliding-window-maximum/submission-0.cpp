class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res(n-k+1); 
        int l = 0, r = 0;

        while (r < n) {
            while (!q.empty() && nums[q.back()] < nums[r]) {
                //removing all elements smaller than our r
                q.pop_back();
            }
            q.push_back(r);
            if (l > q.front()) { 
                //if q.front() is not within bounds of our window
                q.pop_front();
            }

            if (r + 1 >= k) {
                res[l] = nums[q.front()];
                l++;
            }
            r++;
        }

        return res;
    }
};
