class Solution {
public:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (int i = 0; i < points.size(); i++) {
            int dist_squared = pow(points[i][0], 2) + pow(points[i][1], 2);
            vector<int> v; 
            v.push_back(dist_squared);
            v.push_back(points[i][0]);
            v.push_back(points[i][1]);
            pq.push(v);
        }
        vector<vector<int>> ans; 
        for (int i = 0; i < k; i++) {
            vector<int> pr; 
            pr.push_back(pq.top()[1]);
            pr.push_back(pq.top()[2]);
            ans.push_back(pr);
            pq.pop();
        }
        return ans; 
    }
};
