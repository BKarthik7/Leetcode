/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bit_count[24] = {0};
        
        for (int num : candidates) {
            for (int i = 0; i < 24; ++i) {
                if (num & (1 << i)) { 
                    bit_count[i]++;
                }
            }
        }
        
        int max_combination_size = 0;
        for (int count : bit_count) {
            max_combination_size = max(max_combination_size, count);
        }
        
        return max_combination_size;
    }
};

// @lc code=end

