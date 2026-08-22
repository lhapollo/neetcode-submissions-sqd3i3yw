class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        while (true) {
            int cand = nums[rand() % n]; 
            int cnt = 0;
            for (auto num: nums) {
                if (num == cand) cnt++;
            }
            if (cnt > n / 2) return cand;
        }
    }
};