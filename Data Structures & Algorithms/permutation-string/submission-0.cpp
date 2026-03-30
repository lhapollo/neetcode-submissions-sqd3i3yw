class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0), freq2(26,0);
        if (s1.length() > s2.length()) return false; 
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i]-'a']++;
        }
        for (int i = 0; i < s1.length(); i++) {
            freq2[s2[i]-'a']++;
        }
        int n = s1.length(), m = s2.length();
        for (int i = 0; i <= m - n; i++) {
            if (freq1 == freq2) return true;
            if (i + n < m) {
                freq2[s2[i]-'a']--;
                freq2[s2[i+n]-'a']++;
            }
        }
        return false;
    }
};
