class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
       while(!nums.empty())
       {
         //create a set
         set<int> s;

         //all unique elements inserted to s
         for(int i = 0 ; i < nums.size() ; i++)
         {
            s.insert(nums[i]);
         }

         
         for(int x : s)
         {
            //append all elements of s to ans
            ans.push_back(x);

            //find x in nums
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == x)
                {
                    //erase element from nums
                    nums.erase(nums.begin() + i);
                    break;
                }
            }
         }
       }
        return ans;
    } 
};