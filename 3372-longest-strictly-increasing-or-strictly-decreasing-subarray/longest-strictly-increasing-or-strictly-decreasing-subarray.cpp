class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int ans = 1;
        int count = 1;
        int direction = 0;  // 0 for undetermined, 1 for increasing, -1 for decreasing
        
        for(int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                if (direction >= 0) {
                    direction = 1;
                    count++;
                } else {
                    direction = 1;
                    count = 2;
                }
            } else if (nums[i] > nums[i + 1]) {
                if (direction <= 0) {
                    direction = -1;
                    count++;
                } else {
                    direction = -1;
                    count = 2;
                }
            } else {
                count = 1;
                direction = 0;
            }
            ans = max(ans, count);
        }

        return ans;
    }
};
