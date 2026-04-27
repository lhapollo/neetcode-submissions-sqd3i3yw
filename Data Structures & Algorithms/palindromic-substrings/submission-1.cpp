class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            string curr = "";
            int l = i; 
            int r = i;
            while (true) {
                if (l < 0 || r >= s.length()) break;
                if (s[l] != s[r]) break;
                ans++;
                l--;
                r++;
            }
            l = i;
            r= i+1;
            while (true) {
                if (l < 0 || r >= s.length()) break;
                if (s[l] != s[r]) break;
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};
