class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        
        visited[i][j] = true;
        int ans = grid[i][j];
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto [dx, dy] : dir) {
            ans += dfs(i + dx, j + dy, n, m, visited, grid);
        }
        
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    ans = max(ans, dfs(i, j, n, m, visited, grid));
                }
            }
        }

        return ans;
    }
};
