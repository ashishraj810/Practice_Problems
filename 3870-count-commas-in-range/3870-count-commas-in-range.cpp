class Solution {
public:
    int countCommas(int n) {
        
        int ans = 0; 
        
        for(int i = 0 ; i <= n ; i++)
        {
           int num = i;
           int count = 0 ;
           while(num != 0)
           {
             int rem = num % 10;
             count+=1;
             num = num / 10;
           }

           if(count > 3)
           {
            ans += (count-1) / 3;
           }
        }
       return ans; 
    }
};