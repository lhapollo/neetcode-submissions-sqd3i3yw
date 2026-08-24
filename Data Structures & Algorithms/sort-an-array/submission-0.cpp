class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        for (auto num: nums) minHeap.push(num);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = minHeap.top();
            minHeap.pop();
        } 
        return nums; 
    }
};