
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long ans1 = 1LL * need1 * cost1
                       + 1LL * need2 * cost2;

        long long mn = min(need1, need2);
        long long mx = max(need1, need2);

        long long ans2 = mn * costBoth;

        if (need1 > need2) {
            ans2 += (need1 - need2) * 1LL * cost1;
        } else {
            ans2 += (need2 - need1) * 1LL * cost2;
        }

        long long ans3 = mx * costBoth;

        return min({ans1, ans2, ans3});
    }
};
