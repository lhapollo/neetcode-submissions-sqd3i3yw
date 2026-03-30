class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }
            int len = r-l+1;
            ans = max(ans, len);
        }
        return ans;
    }
};
