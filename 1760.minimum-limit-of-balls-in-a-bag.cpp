/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int s = 1, e = *max_element(nums.begin(), nums.end()), m;
        while(s < e){
            m = (s + e) / 2;
            long long c = 0;
            for(int j = 0; j < n && c <= maxOperations; j++){
                c += (nums[j] - 1) / m;
            }
            if(c <= maxOperations) e = m;
            else s = m + 1;
        }
        return e;
    }
};
// @lc code=end

