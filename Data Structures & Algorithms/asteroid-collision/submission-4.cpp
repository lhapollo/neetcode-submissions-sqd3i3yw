class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk; 
        for (int i = 0; i < asteroids.size(); i++) {
            if (stk.empty() || (asteroids[i] > 0 && stk.top() > 0) || (asteroids[i] < 0 && stk.top() < 0)) {
                stk.push(asteroids[i]);
            } else if (stk.top() < 0 && asteroids[i] > 0) stk.push(asteroids[i]);
            else {
                //else, simulate
                bool curr_exploded = false; 
                while (!stk.empty()) {
                    if ((asteroids[i] > 0 && stk.top() > 0) || (asteroids[i] < 0 && stk.top() < 0)) break;
                    else {
                        if (abs(asteroids[i]) > abs(stk.top())) {
                            stk.pop();
                        } else if (abs(asteroids[i]) == abs(stk.top())) {
                            stk.pop();
                            curr_exploded = true; 
                            break;
                        } else {
                            curr_exploded = true; 
                            break; 
                        }
                    }
                }
                if (!curr_exploded) stk.push(asteroids[i]);
            }
        }
        vector<int> ans; 
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};


/*
[-2, -2, 1, -2]
stk:
[-2, -2]
*/