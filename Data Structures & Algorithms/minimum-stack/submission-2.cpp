class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;

    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        if (min_stk.empty()) min_stk.push(val);
        else(min_stk.push(min(val, min_stk.top())));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
