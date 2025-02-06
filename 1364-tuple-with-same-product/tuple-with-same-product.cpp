class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for(auto& [product, count] : mp) {
            if(count >= 2) {
                ans += 8 * (count * (count - 1)) / 2;
            }
        }

        return ans;
    }
};
