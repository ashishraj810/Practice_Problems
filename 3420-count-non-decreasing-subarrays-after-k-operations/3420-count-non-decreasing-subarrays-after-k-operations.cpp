
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;

        while ((1 << LOG) <= n) LOG++;

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        vector<int> nxt(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nxt[i] = st.top();
            }

            st.push(i);
        }

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> cost(LOG, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];

            int len = nxt[i] - i;

            cost[0][i] = 1LL * nums[i] * len
                       - (pref[nxt[i]] - pref[i]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];

                up[j][i] = up[j - 1][mid];

                cost[j][i] = cost[j - 1][i]
                           + cost[j - 1][mid];
            }
        }

        auto getCost = [&](int l, int r) -> long long {

            long long operations = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {

                if (up[j][cur] <= r) {
                    operations += cost[j][cur];
                    cur = up[j][cur];
                }
            }

            operations += 1LL * nums[cur] * (r - cur + 1)
                        - (pref[r + 1] - pref[cur]);

            return operations;
        };

        long long ans = 0;
        int r = -1;

        for (int l = 0; l < n; l++) {

            if (r < l) {
                r = l;
            }

            while (r + 1 < n &&
                   getCost(l, r + 1) <= k) {
                r++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};
