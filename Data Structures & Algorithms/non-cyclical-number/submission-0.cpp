class Solution {
public:
    int sumOfSquares(int num) {
        int ans = 0;
        while (num > 0) {
            int digit = num % 10; 
            ans += (digit * digit);
            num /= 10;
        }
        return ans; 
    }

    bool isHappy(int n) {
        unordered_set<int> nums; 
        while (n != 1) {
            n = sumOfSquares(n);
            if (nums.find(n) != nums.end()) return false; 
            nums.insert(n);
        }
        return true; 
    }
};
