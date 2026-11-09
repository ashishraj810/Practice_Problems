class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int target = 1; target <= 26; target++) {

            int freq[26] = {0};
            int left = 0;
            int unique = 0;
            int countAtLeastK = 0;

            for (int right = 0; right < n; right++) {

                int idx = s[right] - 'a';

                if (freq[idx] == 0) {
                    unique++;
                }

                freq[idx]++;

                if (freq[idx] == k) {
                    countAtLeastK++;
                }

                while (unique > target) {
                    int removeIdx = s[left] - 'a';

                    if (freq[removeIdx] == k) {
                        countAtLeastK--;
                    }

                    freq[removeIdx]--;

                    if (freq[removeIdx] == 0) {
                        unique--;
                    }

                    left++;
                }

                if (unique == target && unique == countAtLeastK) {
                    ans = max(ans, right - left + 1);
                }
            }
        }

        return ans;
    }
};