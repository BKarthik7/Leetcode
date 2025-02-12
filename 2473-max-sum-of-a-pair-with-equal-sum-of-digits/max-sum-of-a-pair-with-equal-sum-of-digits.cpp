class Solution {
public:
    int summ(int num){
        int ans = 0;
        while(num){
            int rem = num % 10;
            ans += rem;
            num /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> mp;
        int ans = -1;
        for(int num : nums){
            mp[summ(num)].push_back(num);
        }
        for(auto &[_,b] : mp){
            sort(b.begin(), b.end());
            int len = b.size();
            if(len >= 2){
                int ans1 = b[len - 1] + b[len - 2];
                ans = max(ans, ans1);
            }
        }
        return ans;
    }
};