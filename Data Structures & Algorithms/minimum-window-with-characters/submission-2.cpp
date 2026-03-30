class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        unordered_map<char, int> t_freq; 
        int counter = 0;
        unordered_map<char, int> s_freq;
        for (int i = 0; i < t.length(); i++) {
            t_freq[t[i]]++;
        }
        string ans = "";
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            if (t_freq.count(s[r]) == 1) { 
                s_freq[s[r]]++; 
                counter++;
            }
            for (auto [key, val]: s_freq) {
                cout << key << " " << val << endl;
            }
            while (!t_freq.count(s[l]) && counter >= t.length() || (t_freq.count(s[l]) && s_freq.at(s[l]) > t_freq.at(s[l]))) {
                s_freq[s[l]]--;
                if (t_freq.count(s[l])) counter--;
                l++;
            }
            bool valid = true;
            for (auto [key, val] : t_freq) {
                if (s_freq.count(key) == 0 || s_freq[key] < val) {
                    valid = false; 
                    break;
                }
            }
            if ((valid && (ans.length() == 0 || r - l + 1 < ans.length()))) {
                ans = "";
                for (int i = l; i <= r; i++) {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};
