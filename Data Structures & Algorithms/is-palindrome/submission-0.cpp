class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {return !std::isalnum(c);}), s.end());
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return std::tolower(c);});
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        int l = 0, r = s.length()-1;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
