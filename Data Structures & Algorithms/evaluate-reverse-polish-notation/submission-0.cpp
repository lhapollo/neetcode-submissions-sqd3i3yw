class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int o2 = stk.top();
                stk.pop();
                int o1 = stk.top();
                stk.pop();
                if (tokens[i] == "+") {
                    stk.push(o1 + o2);
                } else if (tokens[i] == "-") {
                    stk.push(o1 - o2);
                } else if (tokens[i] == "*") {
                    stk.push(o1 * o2);
                } else {
                    stk.push(o1 / o2);
                }
            } else {    
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
