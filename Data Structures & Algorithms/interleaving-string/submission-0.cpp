class Solution {
public:
    vector<vector<int>> memo;

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false; 

        //memo[i][j] = can we form rest of string using last i letters of s1, last j letters of s2
        memo = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return dp(0, 0, 0, s1, s2, s3);
    }

    int dp(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (k == s3.length()) { //if k is at end of string
            return (i == s1.length() && j == s2.length()); //return if we are out of letters of both s1 and s2 
        }

        if (memo[i][j] != -1) return memo[i][j];

        bool res = false; 

        if (i < s1.length() && s1[i] == s3[k]) { //if ith letter of s1 == current kth letter of s3
            res = dp(i+1, j, k+1, s1, s2, s3);
        }

        //checking in case first case fails
        if (!res && j < s2.length() && s2[j] == s3[k]) {//if jth letter of s2 == current kth letter of s3
            res = dp(i, j+1, k+1, s1, s2, s3);
        }

        memo[i][j] = res;
        return res;
    }
};
