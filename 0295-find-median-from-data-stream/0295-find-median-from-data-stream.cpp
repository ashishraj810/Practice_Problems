// class MedianFinder {
// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
        
//     }
    
//     double findMedian() {
        
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 
class MedianFinder {
    priority_queue<int> small; 
    // Max heap: smaller half

    priority_queue<int, vector<int>, greater<int>> large;
    // Min heap: larger half

public:
    MedianFinder() {
    }

    void addNum(int num) {
        small.push(num);

        // Ensure every element in large is >= every element in small
        large.push(small.top());
        small.pop();

        // Keep small at least as large as large
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }

        return ((long long)small.top() + large.top()) / 2.0;
    }
};
