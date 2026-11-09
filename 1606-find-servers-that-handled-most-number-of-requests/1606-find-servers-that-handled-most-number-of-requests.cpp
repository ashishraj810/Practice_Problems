class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishing time, server ID}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> busy;

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // 1. Release servers that have completed requests
            while(!busy.empty() && busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                busy.pop();

                available.insert(server);
            }

            // 2. If all servers are busy, drop request
            if(available.empty()) {
                continue;
            }

            // 3. Find preferred server
            int preferred = i % k;

            auto it = available.lower_bound(preferred);

            // Wrap around if necessary
            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // 4. Assign request
            count[server]++;

            available.erase(it);

            busy.push({arrival[i] + load[i], server});
        }

        // 5. Find maximum number of requests
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};