class MedianFinder {
public:

    // stores smaller half
    priority_queue<int> maxHeap;

    // stores larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // Step 1:
        // insert into max heap
        maxHeap.push(num);

        // Step 2:
        // move largest element to min heap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3:
        // maintain size balance
        if(minHeap.size() > maxHeap.size()) {

            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {

        // odd number of elements
        if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // even number of elements
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};