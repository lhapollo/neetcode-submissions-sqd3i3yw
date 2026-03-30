class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_count[26] = {};
        int t_count[26] = {};
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            s_count[s[i]-'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            t_count[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (s_count[i] != t_count[i]) return false;
        }
        return true;
    }
};
