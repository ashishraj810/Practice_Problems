class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
     vector<int> smaller;  
     vector<int> equal;  
     vector<int> greater;

     for(int i = 0 ; i < nums.size() ; i++)
     {
        if(nums[i] < pivot)
        smaller.push_back(nums[i]);

        else if(nums[i] == pivot)
        equal.push_back(nums[i]);

        else
        greater.push_back(nums[i]);
     } 

     nums.clear();  //to clear nums completely

     nums.insert(nums.end() , smaller.begin() , smaller.end()); 
     nums.insert(nums.end() , equal.begin() , equal.end()); 
     nums.insert(nums.end() , greater.begin() , greater.end());

     return nums; 
    }
};