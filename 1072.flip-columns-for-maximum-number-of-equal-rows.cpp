/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
#include <vector>;
#include <unordered_map>;
#include <string>;
using namespace std;
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> count;
        
        for (const auto& row : matrix) {
            string key;
            bool flip = row[0] == 1;
            
            for (int num : row) {
                key += flip ? ('0' + (1 - num)) : ('0' + num);
            }
            
            count[key]++;
        }
        
        int maxCount = 0;
        for (const auto& pair : count) {
            maxCount = max(maxCount, pair.second);
        }
        
        return maxCount;
    }
};
// @lc code=end

