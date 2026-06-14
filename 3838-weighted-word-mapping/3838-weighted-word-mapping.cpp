class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string res = "";

        for(string word : words)
        {
            int weight = 0;
            char ch = ' ';
            for(int i = 0 ; i < word.length() ; i++)
            {
                weight += weights[word[i] - 'a'];
            }
            
            int num = weight % 26;
            ch = 'z' - num;

            res += ch;
        }
        return res;
    }
};