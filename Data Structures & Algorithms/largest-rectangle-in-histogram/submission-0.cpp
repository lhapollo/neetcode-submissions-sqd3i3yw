class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftmost(n, -1), rightmost(n, n);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                leftmost[i] = stk.top();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                rightmost[i] = stk.top();
            }
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int area = (rightmost[i]-leftmost[i]-1) * heights[i]; 
            ans = max(ans, area);
        }
        return ans; 
    }
};
