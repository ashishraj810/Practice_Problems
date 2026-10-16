class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            set<int> s;

            for (int j = i; j < n; j++) {
                s.insert(nums[j]);

                int count = s.size();
                sum += count * count;
            }
        }

        return sum;
    }
};