/*
 * @lc app=leetcode id=2490 lang=cpp
 *
 * [2490] Circular Sentence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (n == 0) return true; 
        // if (sentence[0] != sentence[n - 1]) return false;

        for (int i = 0; i < n; ++i) {
            if (sentence[i] == ' ' || i == n - 1) {
                char endChar = (i == n - 1) ? sentence[i] : sentence[i - 1];
                char startChar = (i == n - 1) ? sentence[0] : sentence[i + 1];

                if (endChar != startChar) return false;
            }
        }

        return true;
    }
};



// @lc code=end

