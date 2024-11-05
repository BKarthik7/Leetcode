/*
 * @lc app=leetcode id=2914 lang=cpp
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i+=2) if(s[i] != s[i + 1]) ans++;
        return ans;
    }
};
// @lc code=end

