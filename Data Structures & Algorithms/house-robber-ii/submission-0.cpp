class Solution {
public:
    int rec(int num, vector<int>& arr, vector<int>& mem) {
        if (num < 0) return 0;
        if (mem[num] != -1) return mem[num];

        mem[num] = max(
            arr[num] + rec(num - 2, arr, mem),
            rec(num - 1, arr, mem)
        );
        return mem[num];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> arr1(nums.begin() + 1, nums.end()); 
        vector<int> arr2(nums.begin(), nums.end() - 1); 
        vector<int> mem1(arr1.size(), -1);
        vector<int> mem2(arr2.size(), -1);

        return max(
            rec(arr1.size() - 1, arr1, mem1),
            rec(arr2.size() - 1, arr2, mem2)
        );
    }
};
