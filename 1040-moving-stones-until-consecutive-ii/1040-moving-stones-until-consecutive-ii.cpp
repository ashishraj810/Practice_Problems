
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());

        int n = stones.size();

        // Maximum moves
        int maxi = max(stones[n - 2] - stones[0],
                      stones[n - 1] - stones[1]) - (n - 2);

        // Minimum moves using sliding window
        int mini = n;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (stones[right] - stones[left] >= n) {
                left++;
            }

            int count = right - left + 1;
            mini = min(mini, n - count);
        }

        // Special case: minimum moves can be 2 instead of 1
        if (stones[n - 2] - stones[0] == n - 2 &&
            stones[n - 1] - stones[n - 2] > 2) {
            mini = 2;
        }

        if (stones[n - 1] - stones[1] == n - 2 &&
            stones[1] - stones[0] > 2) {
            mini = 2;
        }

        return {mini, maxi};
    }
};