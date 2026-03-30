class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stk; 
        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stk.empty() && stk.top().first < t) {
                auto p = stk.top();
                stk.pop();
                res[p.second] = i - p.second;
            }
            stk.push({t, i});
        }
        return res;
    }
};
