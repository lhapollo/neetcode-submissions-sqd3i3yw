class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_amt = accumulate(gas.begin(), gas.end(), 0);
        int cost_amt = accumulate(cost.begin(), cost.end(), 0);

        if (gas_amt < cost_amt) return -1; 

        int total = 0;
        int res = 0;

        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                res = i+1;
            }
        }

        return res;
    }
};
