class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num: nums) {
            int ind = abs(num)-1;
            if (nums[ind] < 0) return abs(num);
            else nums[ind]*= -1;
        }
        return -1;
    }
};
