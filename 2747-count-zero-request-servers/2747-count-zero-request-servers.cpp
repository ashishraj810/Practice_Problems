
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        unordered_map<int,int> mp;

        vector<int> ans(queries.size());

        int left = 0;
        int right = 0;

        for(int i = 0; i < q.size(); i++) {

            int start = q[i].first - x;
            int end = q[i].first;

            while(right < logs.size() &&
                  logs[right][1] <= end) {

                mp[logs[right][0]]++;
                right++;
            }

            while(left < right &&
                  logs[left][1] < start) {

                int server = logs[left][0];

                mp[server]--;

                if(mp[server] == 0) {
                    mp.erase(server);
                }

                left++;
            }

            ans[q[i].second] = n - mp.size();
        }

        return ans;
    }
};
