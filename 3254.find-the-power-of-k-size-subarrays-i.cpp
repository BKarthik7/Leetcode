/*
 * @lc app=leetcode id=3254 lang=cpp
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n - k + 1, -1);
        if (n == 1) return nums;
        int m = 1;
        for(int i = 1; i < k; i++){
            if(nums[i] == nums[i - 1] + 1) m++;
            else m = 1;
        }

        if(m == k) ans[0] = nums[k - 1];

        for (int l=1, r=k; r<n; l++, r++) {
            if (nums[r]==nums[r-1]+1) m++;
            else m=1;
            if (m>=k) ans[l]=nums[r];
        }
        return ans;        
    }
};
// @lc code=end

