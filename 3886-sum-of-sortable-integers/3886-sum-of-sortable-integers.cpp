class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevLast = INT_MIN;

            for (int i = 0; i < n; i += k) {
                int cnt = 0;
                int pos = -1;

                for (int j = i; j < i + k; j++) {
                    int next = (j + 1 == i + k) ? i : j + 1;

                    if (nums[j] > nums[next]) {
                        cnt++;
                        pos = next;
                    }
                }

                if (cnt > 1) {
                    valid = false;
                    break;
                }

                int start = (pos == -1) ? i : pos;
                int first = nums[start];
                int last = nums[(start + k - 1 - i) % k + i];

                if (first < prevLast) {
                    valid = false;
                    break;
                }

                prevLast = last;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};