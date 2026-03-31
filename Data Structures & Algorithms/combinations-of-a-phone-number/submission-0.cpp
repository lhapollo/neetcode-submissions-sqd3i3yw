class Solution {
public:
    unordered_map<char, vector<char>> um; 
    vector<string> res; 
    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;
        um['2'] = {'a', 'b', 'c'}; 
        um['3'] = {'d', 'e', 'f'}; 
        um['4'] = {'g', 'h', 'i'}; 
        um['5'] = {'j', 'k', 'l'}; 
        um['6'] = {'m', 'n', 'o'}; 
        um['7'] = {'p', 'q', 'r', 's'}; 
        um['8'] = {'t', 'u', 'v'}; 
        um['9'] = {'w', 'x', 'y', 'z'}; 
        string curr = "";
        dfs(curr, digits, 0);
        return res;
    }
    void dfs(string& curr, string& digits, int dig_ind){
        if (dig_ind >= digits.size()) {
            res.push_back(curr);
            return; 
        }
        for (int i = 0; i < um[digits[dig_ind]].size(); i++) {
            curr += um[digits[dig_ind]][i];
            dfs(curr, digits, dig_ind + 1);
            curr.pop_back();
        } 
    }

};
