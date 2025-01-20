#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return -1;
        int n = mat[0].size();
        
        vector<int> rowCount(m, 0), colCount(n, 0);
        unordered_map<int, pair<int, int>> mp;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            auto [rw, cl] = mp[arr[i]];
            rowCount[rw]++;
            if (rowCount[rw] == n) return i;
            
            colCount[cl]++;
            if (colCount[cl] == m) return i;
        }
        
        return -1;
    }
};