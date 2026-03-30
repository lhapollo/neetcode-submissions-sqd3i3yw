class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets; 
        brackets['('] = ')';
        brackets['{'] = '}';
        brackets['['] = ']';
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (brackets.count(s[i]) == 1) {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                if (brackets[st.top()] == s[i]) {
                    st.pop();
                } else return false; 
            }
        }
        return st.empty();
    }
};
