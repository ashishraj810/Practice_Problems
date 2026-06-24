class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        int count = 0;

        sort(costs.begin() , costs.end());

        for(int i = 0 ; i < costs.size() ; i++)
        {
            ans += costs[i];

            if(ans <= coins)
            count++;
            else 
             break;
        }

        return count;
        
    }
};