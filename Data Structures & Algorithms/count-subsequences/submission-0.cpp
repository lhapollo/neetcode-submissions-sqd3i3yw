class Solution {
public:
    vector<vector<int>> memo; 

    int numDistinct(string s, string t) {
        memo = vector<vector<int>> (s.length(), vector<int>(t.length(), -1));
        return dp(0, 0, s, t);
    }

    int dp(int i, int j, string s, string t) {
        if (j >= t.length()) return 1; 
        if (i >= s.length()) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        int res = dp(i+1, j, s, t); //choose to skip current index i
        if (s[i] == t[j]) res += dp(i+1, j+1, s, t); //if current indices match, we increment both indices

        memo[i][j] = res;
        return res;
    }

    //dp(i, j) = number of distinct subsequences of j:: in t using the remaining i:: in s
};
