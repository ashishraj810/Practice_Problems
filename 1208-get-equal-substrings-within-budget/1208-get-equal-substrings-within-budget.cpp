
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int currCost = 0;
        int maxi = 0;

        for (int right = 0; right < s.size(); right++) {

            currCost += abs(s[right] - t[right]);

            while (currCost > maxCost) {
                currCost -= abs(s[left] - t[left]);
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};