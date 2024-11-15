/*
 * @lc app=leetcode id=1574 lang=cpp
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), left = 0, right = n - 1;
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        if (left == n - 1) {
            return 0;
        }

        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        int result = min(n - left - 1, right);
        int i = 0, j = right;
        while( i < left + 1 && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return result;
        
    }
};
// @lc code=end

