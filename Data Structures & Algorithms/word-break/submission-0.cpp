class Solution {
public:
    vector<int> memo;

    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.length(), -1);
        return dp(0, s, wordDict);
    }

    bool dp(int ind, string s, vector<string>& wordDict) {
        if (ind == s.length()) return true;
        if(memo[ind] != -1) return memo[ind] == 0? false: true;

        for (auto word: wordDict) {
            if (ind + word.length() <= s.length() && s.substr(ind, word.length()) == word) {
                if (dp(ind + word.length(), s, wordDict)) {
                    memo[ind] = 1;
                    return true;
                }
            }
        }

        memo[ind] = 0;
        return false; 
    }
};
