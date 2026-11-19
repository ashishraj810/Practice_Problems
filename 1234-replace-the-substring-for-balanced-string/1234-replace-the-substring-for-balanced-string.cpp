
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int target = n / 4;

        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        if (mp['Q'] == target && mp['W'] == target &&
            mp['E'] == target && mp['R'] == target) {
            return 0;
        }

        int left = 0;
        int mini = n;

        for (int right = 0; right < n; right++) {

            mp[s[right]]--;

            while (mp['Q'] <= target &&
                   mp['W'] <= target &&
                   mp['E'] <= target &&
                   mp['R'] <= target) {

                mini = min(mini, right - left + 1);

                mp[s[left]]++;
                left++;
            }
        }

        return mini;
    }
};