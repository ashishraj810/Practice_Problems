class Solution {
public:

void permute(vector<int>& nums ,vector<vector<int> >&ans ,int index)
{
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i=index ; i<nums.size() ; i++)
    {
        swap(nums[index],nums[i]);
        permute(nums ,ans ,index+1);
        swap(nums[index],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
      
       vector<vector<int> >ans;
       permute(nums, ans ,0);
       return ans;
    }
    
};