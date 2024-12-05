/*
 * @lc app=leetcode id=2337 lang=cpp
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
        bool canChange(string start, string target) {
        int n = start.size();
        
        string s, t;
        for (char c : start) {
            if (c != '_') s += c;
        }
        for (char c : target) {
            if (c != '_') t += c;
        }
        if (s != t) return false;

        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            if (i == n || j == n) break;

            if (start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false; 
            if (start[i] == 'R' && i > j) return false; 

            i++;
            j++;
        }

        return true;
    }
};
// @lc code=end

