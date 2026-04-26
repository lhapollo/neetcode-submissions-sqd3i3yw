class Solution {
public:
    vector<int> memo = vector<int>(50, 0);
    
    int climbStairs(int n) {
        memo[1] = 1;
        memo[2] = 2;

        for (int i = 3; i <= n; i++) {
            memo[i] = memo[i-1] + memo[i-2];
        }

        return memo[n];

    }
};
