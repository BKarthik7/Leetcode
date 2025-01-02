/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        int n = words.size();
        vector<int> prefixSum(n, 0);

        for (int i = 0; i < n; ++i) {
            bool isVowelString = isVowel(words[i][0]) && isVowel(words[i].back());
            prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0) + isVowelString;
        }

        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            int count = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
            ans.push_back(count);
        }

        return ans;
    }
};

// @lc code=end

