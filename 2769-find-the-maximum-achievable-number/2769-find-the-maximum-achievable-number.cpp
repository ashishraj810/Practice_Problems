class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int x;   //achievable
        
        //we are allowed to: achievable - t = num + t
        //=>achievable = num + 2*t;

        x = num + 2*t;
        return x;

    }
};