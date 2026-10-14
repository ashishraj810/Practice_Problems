// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i = 0;
//         int j = 1;

//         for(int j = 1 ; j < nums.size() ; j++)
//         {
//             if(nums[i] != nums[j])
//             {
//                 i++;
//                 nums[i] = nums[j];
//             }
//             else
//             {

//             }
//         }
//         return (i+1);
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            s.insert(nums[i]);
        }

        nums.clear();
        for(auto x : s)
       {
         nums.push_back(x);
        }

        int ans = s.size();
        return ans;
       
    }
};
