
class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
public:

    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, vector<string>& ans) {

        int m = board.size();
        int n = board[0].size();

        char ch = board[i][j];
        int idx = ch - 'a';

        TrieNode* child = node->children[idx];

        if(child == nullptr) return;

        // Found a complete word
        if(child->word != "") {
            ans.push_back(child->word);
            child->word = "";
        }

        // Mark current cell as visited
        board[i][j] = '#';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Explore all four directions
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < m &&
               nj >= 0 && nj < n &&
               board[ni][nj] != '#') {

                dfs(board, ni, nj, child, ans);
            }
        }

        // Backtracking: restore original character
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        // Build Trie
        for(string& word : words) {
            insert(root, word);
        }

        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        // Start DFS from every cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};