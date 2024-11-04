/*
 * @lc app=leetcode id=3163 lang=cpp
 *
 * [3163] String Compression III
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size();
        int i = 0;
        while (i < n) {
            char c = word[i];
            int count = 0;
            while (i < n && count < 9 && word[i] == c) {
                count++;
                i++;
            }
            comp += to_string(count) + c;
        }
        return comp;
    }
};
// @lc code=end

