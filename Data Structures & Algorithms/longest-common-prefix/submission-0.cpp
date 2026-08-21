class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ind = 0; 
        string ans = "";
        while (true) {
            bool flag = false; 
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i].length() <= ind) flag = true; 
                if (strs[i][ind] != strs[0][ind]) flag = true; 
            }
            if (flag) break; 
            ans += strs[0][ind];
            ind++;
        }
        return ans; 
    }
};