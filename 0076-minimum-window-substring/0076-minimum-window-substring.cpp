class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);

        // Store frequency of characters in t
        for(char c : t) {
            freq[c]++;
        }

        int left = 0;
        int right = 0;

        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()) {

            // Include current character
            if(freq[s[right]] > 0) {
                required--;
            }

            freq[s[right]]--;
            right++;

            // All required characters are present
            while(required == 0) {

                // Update minimum window
                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Remove left character
                freq[s[left]]++;

                if(freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
