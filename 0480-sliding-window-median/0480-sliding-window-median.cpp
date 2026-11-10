
class Solution {
public:
    priority_queue<int> small; 
    // Max heap: smaller half

    priority_queue<int, vector<int>, greater<int>> large;
    // Min heap: larger half

    unordered_map<int, int> delayed;

    int smallSize = 0;
    int largeSize = 0;

    // Remove elements marked for deletion from max heap
    void pruneSmall() {
        while (!small.empty()) {
            int num = small.top();

            if (delayed[num] > 0) {
                small.pop();
                delayed[num]--;
            }
            else {
                break;
            }
        }
    }

    // Remove elements marked for deletion from min heap
    void pruneLarge() {
        while (!large.empty()) {
            int num = large.top();

            if (delayed[num] > 0) {
                large.pop();
                delayed[num]--;
            }
            else {
                break;
            }
        }
    }

    // Balance the two heaps
    void balance() {

        if (smallSize > largeSize + 1) {
            pruneSmall();

            int num = small.top();
            small.pop();

            large.push(num);

            smallSize--;
            largeSize++;

            pruneSmall();
        }
        else if (smallSize < largeSize) {
            pruneLarge();

            int num = large.top();
            large.pop();

            small.push(num);

            largeSize--;
            smallSize++;

            pruneLarge();
        }
    }

    // Insert a new number
    void addNum(int num) {

        if (small.empty() || num <= small.top()) {
            small.push(num);
            smallSize++;
        }
        else {
            large.push(num);
            largeSize++;
        }

        balance();
    }

    // Remove an outgoing number
    void removeNum(int num) {

        delayed[num]++;

        if (num <= small.top()) {
            smallSize--;

            if (num == small.top()) {
                pruneSmall();
            }
        }
        else {
            largeSize--;

            if (!large.empty() && num == large.top()) {
                pruneLarge();
            }
        }

        balance();
    }

    // Calculate current median
    double getMedian(int k) {

        if (k % 2 == 1) {
            return (double)small.top();
        }

        return ((double)small.top() + (double)large.top()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        // First window
        for (int i = 0; i < k; i++) {
            addNum(nums[i]);
        }

        ans.push_back(getMedian(k));

        // Slide the window
        for (int i = k; i < nums.size(); i++) {

            // Remove outgoing element
            removeNum(nums[i - k]);

            // Insert incoming element
            addNum(nums[i]);

            ans.push_back(getMedian(k));
        }

        return ans;
    }
};
