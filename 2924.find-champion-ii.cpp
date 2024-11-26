/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m = edges.size(), ans = 0; 
        set<int> a;
        for(int i = 0; i < m; i++){
            a.insert(edges[i][1]);
        }
        if(a.size() < n - 1) return -1;
        for(int i = 0; i < n; i++) ans ^= i;
        for(auto i : a) ans ^= i;
        return ans;
    }
};
// @lc code=end

