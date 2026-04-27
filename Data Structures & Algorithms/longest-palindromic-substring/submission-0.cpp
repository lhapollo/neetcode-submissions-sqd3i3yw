class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            string odd_curr = "";
            int l = i;
            int r = i;
            while (true) {
                if (l < 0 || r >= s.length()) break; 
                if (s[l] != s[r]) break;
                else odd_curr = s.substr(l, r-l+1);
                if (odd_curr.length() > ans.length()) ans = odd_curr;
                l--;
                r++;
            }

            l = i;
            r = i+1;
            string even_curr = "";
            while (true) {
                if (l < 0 || r >= s.length()) break;
                if (s[l] != s[r]) break;
                else even_curr = s.substr(l, r-l+1);
                if (even_curr.length() > ans.length()) ans = even_curr;
                l--;
                r++;
            }
        }
        return ans;
    }
};
