/*
 * @lc app=leetcode id=2577 lang=cpp
 *
 * [2577] Minimum Time to Visit a Cell In a Grid
 */

// @lc code=start
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        int m = grid.size(), n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
            pq;
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        d[0][0] = 0;
        while (!pq.empty()) {
            auto [v, i, j] = pq.top();
            pq.pop();
            if (i == m - 1 && j == n - 1)
                return v;
            int dir[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int a = i + dir[k], b = j + dir[k + 1];
                if (a >= 0 && a < m && b >= 0 && b < n) {
                    int diff = grid[a][b] - v;
                    if (diff < 0)
                        diff = 0;
                    else if (diff & 1)
                        diff = diff / 2 * 2;
                    int c = v + 1 + diff;
                    if (d[a][b] > c) {
                        d[a][b] = c;
                        pq.push({c, a, b});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

