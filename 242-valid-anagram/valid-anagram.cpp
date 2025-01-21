class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> mp(26, 0);

        for(char c: s) mp[c - 'a']++;
        for(char c: t) mp[c - 'a']--;
        for(int c: mp) if(c != 0) return false;
        return true;
    }
};