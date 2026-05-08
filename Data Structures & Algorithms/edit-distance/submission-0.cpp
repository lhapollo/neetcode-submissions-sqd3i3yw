class Solution {
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length(); 

        memo = vector<vector<int>>(m, vector<int>(n, -1));

        return dp(0, 0, word1, word2);
    }

    int dp(int i, int j, string word1, string word2) {
        if (i == word1.length()) return word2.length() - j;
        if (j == word2.length()) return word1.length() - i;

        if (memo[i][j] != -1) return memo[i][j];

        if (word1[i] == word2[j]) { //current position is ok, no need to edit
            return memo[i][j] = dp(i+1, j+1, word1, word2); 
        }

        //three cases
        int ins_op = 1 + dp(i, j+1, word1, word2);
        int del_op = 1 + dp(i+1, j, word1, word2);
        int repl_op = 1 + dp(i+1, j+1, word1, word2);

        return memo[i][j] = min({ins_op, del_op, repl_op});
    }

    //dp[i][j] = min edit distance, state first i letters, first j letters
};

//monasdfas
//monkey

