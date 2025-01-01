/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int cnt = 0, cnt1 = 0, ans = -1;
        for(char c : s){
            if(c == '1') cnt ++;
        }

        if (s[0] == '0') cnt1++;
        else cnt--;

        for(int i = 1; i < s.length(); i++){
            ans = max(ans, cnt1 + cnt);
            if (s[i] == '0') cnt1++;
            else cnt--;
        }
        return ans;
    }
};
// @lc code=end

