class Solution {
public: 
    void rec(int open, int close, int n, vector<string>& ans, string& curr) {
        if (open == close && open == n) {
            ans.push_back(curr);
            return; 
        }
        if (open < n) {
            curr += '(';
            rec(open+1, close, n, ans, curr);
            curr.pop_back();
        }
        if (close < open) {
            curr += ')';
            rec(open, close+1, n, ans, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        string curr = "";
        rec(0, 0, n, ans, curr);
        return ans; 
    }
};
