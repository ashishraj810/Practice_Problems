class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int num : nums) {
            // Option 1: Increase num to num + 1
            dp[num + 1] = max(dp[num + 1], dp[num] + 1);

            // Option 2: Keep num unchanged
            dp[num] = max(dp[num], dp[num - 1] + 1);

            ans = max(ans, max(dp[num], dp[num + 1]));
        }

        return ans;
    }
};