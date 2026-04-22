class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj; 
        for (auto ticket: tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, destinations]: adj) {
            sort(destinations.rbegin(), destinations.rend());
        }

        vector<string> ans; 
        stack<string> stk;
        stk.push("JFK");

        while (!stk.empty()) {
            string curr = stk.top();
            
            //if the current airport has no outgoing edges, we push it as a result. 
            if (adj[curr].empty()) {
                ans.push_back(curr);
                stk.pop();
            } else {
                string next = adj[curr].back(); //the backmost airport neighbor
                adj[curr].pop_back();
                stk.push(next);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans; 
    }
};
