class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size();
    int n = isWater[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j] == 1) {
          q.push({i, j});
          ans[i][j] = 0;
        }
      }
    }

    const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (auto& [dx, dy] : dirs) {
        int x = i + dx, y = j + dy;
        if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
          ans[x][y] = ans[i][j] + 1;
          q.push({x, y});
        }
      }
    }

    return ans;
  }
};