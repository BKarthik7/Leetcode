/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        
        for (int i = 0; i < m; i++) {
            int emptySpot = n - 1; 
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    emptySpot = j - 1;
                    ans[j][m - 1 - i] = '*';
                } else if (box[i][j] == '#') {
                    ans[emptySpot][m - 1 - i] = '#';
                    emptySpot--;
                }
            }
        }
        
        return ans;
    }
};

// @lc code=end

