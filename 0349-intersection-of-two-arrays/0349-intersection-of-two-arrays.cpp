// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         int i = 0;
//         int j = 0;

//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());

//         while(i < nums1.size() && j < nums2.size())
//         {
//             if(nums1[i] < nums2[j])
//             i++;

//             else if(nums1[i] > nums2[j])
//             j++;

//             else
//             {
//                 if(ans.size() == 0 || ans.back() != nums1[i])
//                 {
//                     ans.push_back(nums1[i]);
//                 }
//                 i++;
//                 j++;
//             }
           
//         }
//          return ans;
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        //to store answer
        vector<int> ans;

        //to store one of the arrays
        unordered_set<int> st;

        //store all elements of nums1 into  unordered_set
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            st.insert(nums1[i]);
        }

        for(int i = 0 ; i < nums2.size() ; i++)
        {
            if(st.find(nums2[i]) != st.end())
            {
                //store that element into ans
                ans.push_back(nums2[i]);

                //erase that element from unordered set
                st.erase(nums2[i]);
            }
        }
        return ans;
    
    }
};