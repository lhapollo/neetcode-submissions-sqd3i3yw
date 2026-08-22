class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        int k = nums.size(); 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                k--; 
                continue; 
            } else {
                nums[j] = nums[i];
                j++;
            }
        }
        return k; 
    }
};