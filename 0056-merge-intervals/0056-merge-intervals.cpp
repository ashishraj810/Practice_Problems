
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(auto &it : intervals) {

            // If ans is empty OR no overlap
            if(ans.empty() || ans.back()[1] < it[0]) {
                ans.push_back(it);
            }
            else {
                // Merge overlapping intervals
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }

        return ans;
    }
};
