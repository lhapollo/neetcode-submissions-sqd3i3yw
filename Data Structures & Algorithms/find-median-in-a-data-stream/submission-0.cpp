class MedianFinder {
public:
    int size = 0;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!min_heap.empty() && num > min_heap.top()) min_heap.push(num);
        else max_heap.push(num);
        size++;

        int max_size = max_heap.size();
        int min_size = min_heap.size();

        if ( abs(max_size - min_size) > 1) {
            if (max_heap.size() > min_heap.size()) {
                int val = max_heap.top();
                max_heap.pop();
                min_heap.push(val);
            } else {
                int val = min_heap.top();
                min_heap.pop();
                max_heap.push(val);
            }
        }
    }
    
    double findMedian() {
        if (size % 2 == 0) {
            return ((max_heap.top() * 1.0) + (min_heap.top()*1.0)) / 2.0;
        } else {
            if (max_heap.size() > min_heap.size()) return (double) max_heap.top();
            else return (double) min_heap.top();
        }
    }
};
