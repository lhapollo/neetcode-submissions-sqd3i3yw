class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        int expected_sum = ((n)*(n+1))/2; 
        int sum = 0;
        for (int num: nums) {
            sum += num; 
        }
        return expected_sum - sum; 
    }
};
