class Solution {
public:
    vector<vector<int>> memo; 

    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();

        memo = vector<vector<int>>(s_len + 5, vector<int>(p_len + 5, -1));

        return dp(0, 0, s, p, s_len, p_len);
    }

    //want to check if p matches s
    bool dp(int i, int j, string s, string p, int s_len, int p_len) {
        if (j == p_len) return i == s_len;
        if (memo[i][j] != -1) return memo[i][j];

        bool match = i < s_len && (s[i] == p[j] || p[j] == '.'); //if current characters match or current pattern is .

        //if we encounter a * as the next character in pattern
        if (j + 1 < p_len && p[j+1] == '*') {
            //either skip the * entirely OR if current chars match, see if consuming a * on matching character works
            memo[i][j] = dp(i, j+2, s, p, s_len, p_len) || (match && dp(i+1, j, s, p, s_len, p_len));
        } else {
            memo[i][j] = match && dp(i+1, j+1, s, p, s_len, p_len); //memo is true if current chars match and dp(i+1, j+1) is true
        }

        return memo[i][j];

    }
};
