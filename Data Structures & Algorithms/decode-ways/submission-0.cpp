class Solution {
public:
    vector<int> memo;

    int numDecodings(string s) {
        memo = vector<int>(s.length(), -1);
        return rec(0, s);
    }

    int rec(int i, string &s) {
        if (i == s.length()) return 1;   // ✅ base case
        if (s[i] == '0') return 0;       // ❌ cannot decode 0
        if (memo[i] != -1) return memo[i];

        int ways = rec(i + 1, s); // take one digit

        // take two digits if valid
        if (i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            if (num >= 10 && num <= 26) {
                ways += rec(i + 2, s);
            }
        }

        return memo[i] = ways;
    }
};