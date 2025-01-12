class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        sort(s.begin(), s.end());
        int ans = 0;

        for (int i = 0; i < s.length(); ) {
            char curr = s[i];
            int c = 0;
            while (i < s.length() && s[i] == curr) {
                c++;
                i++;
            }
            if (c % 2 != 0) ans++;
        }

        return ans <= k;
    }
};