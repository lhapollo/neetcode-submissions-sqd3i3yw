class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<int> sorted_queries = queries;
        sort(sorted_queries.begin(), sorted_queries.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        map<int, int> query_ans;

        int i = 0;

        for (int q : sorted_queries) {

            // Add every interval that starts before/at q
            while (i < intervals.size() && intervals[i][0] <= q) {
                int length = intervals[i][1] - intervals[i][0] + 1;

                min_heap.push({
                    length,
                    intervals[i][0],
                    intervals[i][1]
                });

                i++;
            }

            // Remove intervals that ended before q
            while (!min_heap.empty() && min_heap.top()[2] < q) {
                min_heap.pop();
            }

            query_ans[q] = min_heap.empty() ? -1 : min_heap.top()[0];
        }

        vector<int> ans;

        for (int q : queries) {
            ans.push_back(query_ans[q]);
        }

        return ans;
    }
};