class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
     int left = 0;
     vector<int> ans(nums.size());

     for(int i = 0 ; i < nums.size() ; i++)
     {
       if(nums[i] < pivot)
       {
         ans[left] = nums[i];
         left++;
       }
       
     } 

     for(int i = 0 ; i < nums.size() ; i++)
     {
       if(nums[i] == pivot)
       {
        ans[left] = pivot;
        left++;
       }
       
     } 

     for(int i = 0 ; i < nums.size() ; i++)
     {
       if(nums[i] > pivot)
       {
        ans[left] = nums[i];
        left++;
       }
       
     } 

     return ans; 
    }
};