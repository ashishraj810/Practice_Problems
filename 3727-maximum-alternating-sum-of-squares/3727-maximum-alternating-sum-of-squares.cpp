class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back(nums[i] * nums[i]);
        }

        sort(arr.begin(), arr.end());

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                sum += arr[n - 1 - i];
            } else {
                sum -= arr[n - 1 - i];
            }
        }

        return sum;
    }
};