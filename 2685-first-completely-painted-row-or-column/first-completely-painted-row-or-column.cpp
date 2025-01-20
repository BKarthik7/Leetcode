class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> r(m, 0), c(n, 0);
        unordered_map<int, pair<int, int>> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }
        int ans = 0;
        for(int i = 0; i < m * n; i++){
            auto [ rw, cl ] = mp[arr[i]];
            r[rw]++;
            if(r[rw] >= n) return i;
            c[cl]++;
            if(c[cl] >= m) return i;
        }
        return -1;
    }
};