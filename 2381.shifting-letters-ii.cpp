/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> rotate(n + 1, 0);

        for (auto& shift : shifts) {
            int a = shift[0], b = shift[1], c = shift[2];
            rotate[a] += (c == 1 ? 1 : -1);
            if (b + 1 < n) {
                rotate[b + 1] -= (c == 1 ? 1 : -1);
            }
        }

        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += rotate[i];
            int newChar = ((s[i] - 'a') + netShift) % 26;
            if (newChar < 0) newChar += 26;
            s[i] = 'a' + newChar;
        }

        return s;
    }
};

// @lc code=end

