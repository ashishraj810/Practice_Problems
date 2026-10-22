class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // Case 1: Rotate the original array
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int k = (n - nums[0]) % n;
            ans = min(ans, min(k, n - k + 2));
        }

        // Case 2: Reverse, then rotate
        ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[n - 1 - i] != (nums[n - 1] + i) % n) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int k = (n - nums[n - 1]) % n;
            ans = min(ans, min(k, n - k) + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
