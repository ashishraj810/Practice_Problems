
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int groups = d;
                    int q = len / d;

                    int changes = 0;

                    for (int i = 0; i < groups; i++) {

                        for (int j = 0; j < q / 2; j++) {

                            int x = l + i + j * d;
                            int y = l + i + (q - 1 - j) * d;

                            if (s[x] != s[y])
                                changes++;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // DP
        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 2 * parts; i <= n; i++) {

                for (int p = 2 * (parts - 1);
                     p <= i - 2; p++) {

                    if (dp[p][parts - 1] == INF)
                        continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[p][parts - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
