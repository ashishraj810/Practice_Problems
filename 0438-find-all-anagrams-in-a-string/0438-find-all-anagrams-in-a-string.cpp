class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        
        int n = s.size();
        int m = p.size();
        
        if(m > n) return ans;
        
        vector<int> freq(26, 0);
        vector<int> window(26, 0);
        
        // Store frequency of characters in p
        for(int i = 0; i < m; i++) {
            freq[p[i] - 'a']++;
        }
        
        int left = 0;
        
        for(int right = 0; right < n; right++) {
            
            // Add current character
            window[s[right] - 'a']++;
            
            // Maintain window size m
            if(right - left + 1 > m) {
                window[s[left] - 'a']--;
                left++;
            }
            
            // Check if current window is an anagram
            if(right - left + 1 == m && freq == window) {
                ans.push_back(left);
            }
        }
        
        return ans;
    }
};
