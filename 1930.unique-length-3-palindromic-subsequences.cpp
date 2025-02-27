/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int n = s.length();
        
        unordered_map<char, pair<int, int>> M;
        
        for (int i = 0; i < n; i++) {
            if (M.find(s[i]) == M.end()) {
                M[s[i]].first = i;
            }
            M[s[i]].second = i;
        }
        
        for (auto& [ch, positions] : M) {
            int left = positions.first;
            int right = positions.second;
            
            if (right - left <= 1) continue;  
            
            unordered_set<char> uniqueChars;
            for (int i = left + 1; i < right; i++) {
                uniqueChars.insert(s[i]);
            }
            
            ans += uniqueChars.size();
        }
        
        return ans;
    }
};
// @lc code=end

