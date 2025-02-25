class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1, sum = 0, ans = 0, MOD = 1e9 + 7;
        
        for(int num : arr) {
            sum += num;
            if(sum % 2) {
                ans = (ans + even) % MOD;
                odd++;
            } else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }
        return ans;
    }
};
