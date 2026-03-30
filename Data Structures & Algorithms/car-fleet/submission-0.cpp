class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pi;
        for (int i = 0; i < position.size(); i++) {
            pi.push_back({position[i], speed[i]});
        }
        sort(pi.rbegin(), pi.rend());
        stack<double> times; 
        for (int i = 0; i < pi.size(); i++) {
            double time = (double)(target - pi[i].first) / pi[i].second;
            if (times.empty() || time > times.top()) {
                times.push(time);
            } 
        }
        return times.size();
    }
};

/*
[(7,1) + (4, 2), (1, 2), (0, 1)]]
[3, 4.5, 10]
*/
