class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_set<string> seen, ans;

        if(s.size() < 10)
            return {};

        for(int i = 0; i <= s.size() - 10; i++) {

            string temp = s.substr(i, 10);

            if(seen.find(temp) != seen.end()) {
                ans.insert(temp);
            }
            else {
                seen.insert(temp);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};