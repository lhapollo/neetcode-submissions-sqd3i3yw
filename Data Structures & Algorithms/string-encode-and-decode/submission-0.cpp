class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs.size(); i++) {
            int len = strs[i].length(); 
            ans += to_string(len) + "#" + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans; 
        int i = 0;
        string num = "";
        bool readnum = true;
        while (i < s.length()) {
            if (readnum) {
                num += s[i];
                i++;
            }
            if (s[i] == '#') {
                readnum = false;
                i++;
                int n = stoi(num);
                string str_ans;
                for (int j = 0; j < n; j++) {
                    str_ans += s[i];
                    i++; 
                }
                ans.emplace_back(str_ans);
                num = "";
                readnum = true;
            }
        }
        return ans; 
    }
};
