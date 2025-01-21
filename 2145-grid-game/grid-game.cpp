class Solution {
public:
    long long pickpoints(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixTop(n, 0), prefixBottom(n, 0);

        prefixTop[0] = grid[0][0];
        prefixBottom[0] = grid[1][0];
        for (int j = 1; j < n; ++j) {
            prefixTop[j] = prefixTop[j - 1] + grid[0][j];
            prefixBottom[j] = prefixBottom[j - 1] + grid[1][j];
        }

        long long maxPoints = LLONG_MAX;
        int bestColumn = -1;

        for (int j = 0; j < n; ++j) {
            long long pointsAbove = prefixTop[n - 1] - prefixTop[j];
            long long pointsBelow = (j > 0 ? prefixBottom[j - 1] : 0);
            long long secondRobotPoints = max(pointsAbove, pointsBelow);

            if (secondRobotPoints < maxPoints) {
                maxPoints = secondRobotPoints;
                bestColumn = j;
            }
        }

        for (int j = 0; j <= bestColumn; ++j) grid[0][j] = 0;
        for (int j = bestColumn; j < n; ++j) grid[1][j] = 0;

        return maxPoints;
    }

    long long gridGame(vector<vector<int>>& grid) {
        return pickpoints(grid);
    }
};
