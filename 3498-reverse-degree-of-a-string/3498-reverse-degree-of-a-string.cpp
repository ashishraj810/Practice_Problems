class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            char ch = s[i];
            int value = 'z' - ch + 1;

            int ans = value * (i+1);
            sum = sum + ans; 
        }
        return sum;
        
    }
};