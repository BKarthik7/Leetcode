class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> islandSize;
        int index = 2, maxSize = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};

        function<int(int, int, int)> dfs = [&](int i, int j, int idx) {
            if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return 0;
            grid[i][j] = idx;
            int size = 1;
            for (int d = 0; d < 4; d++) 
                size += dfs(i + dirs[d], j + dirs[d + 1], idx);
            return size;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, index);
                    islandSize[index++] = size;
                    maxSize = max(maxSize, size);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dirs[d], nj = j + dirs[d + 1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] > 1) 
                            neighbors.insert(grid[ni][nj]);
                    }
                    int possibleSize = 1;
                    for (int idx : neighbors) possibleSize += islandSize[idx];
                    maxSize = max(maxSize, possibleSize);
                }
            }
        }

        return maxSize;
    }
};
