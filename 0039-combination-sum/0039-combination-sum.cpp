// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
//     }
// };

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == candidates.size() || target < 0) {
            return;
        }

        // Include the current element
        temp.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], idx);

        // Backtrack: remove the current element
        temp.pop_back();

        // Exclude the current element
        solve(candidates, target, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};
