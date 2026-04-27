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
                curr = s.substr(l, r-l+1);
                ans++;
                l--;
                r++;
            }
            curr = "";
            l = i;
            r= i+1;
            while (true) {
                if (l < 0 || r >= s.length()) break;
                if (s[l] != s[r]) break;
                curr = s.substr(l, r-l+1);
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};
