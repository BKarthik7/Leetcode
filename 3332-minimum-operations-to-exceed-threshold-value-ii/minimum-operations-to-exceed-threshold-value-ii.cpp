class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
        for (int i = 0, x, y; ; ++i) {
            x = q.top();
            q.pop();
            if (x >= k) return i;
            y = q.top();
            q.pop();
            long t = 2L * x + y;
            q.push(t < k ? (int)t : k);
        }
        return -1;
    }
};