class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0, prefix_sum = 0, ans = 0;
        
        for (int num : nums) {
            prefix_sum += num;
            ans = max(ans, abs(prefix_sum - min_sum));
            ans = max(ans, abs(prefix_sum - max_sum));
            max_sum = max(max_sum, prefix_sum);
            min_sum = min(min_sum, prefix_sum);
        }
        
        return ans;
    }
};
