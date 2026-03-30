class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = -1;
        for (int i = 0; i < piles.size(); i++) {
            m = max(m, piles[i]);
        }
        int l = 1; 
        int ans = m;
        while (l <= m) {
            int mid = (l+m)/2;
            int tot = 0;
            for (int i = 0; i < piles.size(); i++) {
                int time = ceil(static_cast<double>(piles[i]) / mid);
                tot += time;
            }
            if (tot <= h) {
                ans = mid;
                m = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};
