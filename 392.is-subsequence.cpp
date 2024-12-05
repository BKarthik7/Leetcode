/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0, m = s.size();
        for (char c : t) {
            if (k < m && s[k] == c) k++;
        }
        return k == m;  // All characters in `s` should be matched
    }
};

// @lc code=end

