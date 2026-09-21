class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int left = 0;
        unordered_map<char , int> count;

        for(int right = 0 ; right < s.length() ; right++)
        {
            char c = s[right];
            count[c] = count[c] + 1;

            while(count[c] > 1)
            {
                char leftchar = s[left];
                count[leftchar] = count[leftchar]-1;
                left++;
            }

            maxlength = max(maxlength , right-left+1);
        }
        
        return maxlength;

    }
};