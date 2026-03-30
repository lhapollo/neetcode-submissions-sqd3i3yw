class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        unordered_map<char, int> t_freq;
        for (char c : t) t_freq[c]++;

        unordered_map<char, int> window;
        int required = t_freq.size(); // number of unique chars needed
        int formed = 0;

        int l = 0;
        int bestLen = INT_MAX;
        int bestL = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            // only count if this char is needed and just matched its required freq
            if (t_freq.count(c) && window[c] == t_freq[c]) {
                formed++;
            }

            // try to shrink window
            while (formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (t_freq.count(leftChar) &&
                    window[leftChar] < t_freq[leftChar]) {
                    formed--;
                }

                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};
