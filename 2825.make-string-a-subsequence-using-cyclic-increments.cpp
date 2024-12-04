/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int k = 0, m = str1.size();
        for (char s : str2) {
            while (k < m && str1[k] != s && ((str1[k] - 'a' + 1) % 26 + 'a') != s) {
                k++;
            }
            if (k == m) return false;
            k++;
        }
        return true;
    }
};

// @lc code=end

