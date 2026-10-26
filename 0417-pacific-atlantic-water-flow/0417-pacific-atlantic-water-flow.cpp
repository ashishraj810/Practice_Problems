class Solution {
public:
    int m, n;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {
        
        visited[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (visited[nr][nc])
                continue;

            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top and left borders
        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
        }

        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
        }

        // Atlantic: bottom and right borders
        for (int j = 0; j < n; j++) {
            dfs(m - 1, j, heights, atlantic);
        }

        for (int i = 0; i < m; i++) {
            dfs(i, n - 1, heights, atlantic);
        }

        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
