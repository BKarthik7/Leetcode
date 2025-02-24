class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> bobTime(n, -1);
        function<bool(int, int, int)> findBobPath = [&](int node, int parent, int time) {
            if (node == 0) {
                bobTime[node] = time;
                return true;
            }
            for (int next : adj[node]) {
                if (next != parent && findBobPath(next, node, time + 1)) {
                    bobTime[node] = time;
                    return true;
                }
            }
            return false;
        };
        findBobPath(bob, -1, 0);

        function<int(int, int, int)> dfs = [&](int node, int parent, int time) {
            int income = 0;
            if (bobTime[node] == -1 || time < bobTime[node]) {
                income = amount[node];
            } else if (time == bobTime[node]) {
                income = amount[node] / 2;
            }

            int maxProfit = INT_MIN;
            bool isLeaf = true;
            for (int next : adj[node]) {
                if (next != parent) {
                    isLeaf = false;
                    maxProfit = max(maxProfit, dfs(next, node, time + 1));
                }
            }
            return income + (isLeaf ? 0 : maxProfit);
        };

        return dfs(0, -1, 0);
    }
};
