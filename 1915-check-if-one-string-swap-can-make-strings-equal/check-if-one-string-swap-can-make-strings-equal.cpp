class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char char1 = 0, char2 = 0;
        int count = 0;
        int n = s1.length();
        if(n != s2.length()) return false;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                count ++;
                if(count == 2 && (char1 != s2[i] || char2 != s1[i])) return false;
                else if(count > 2) return false;
                else{
                    char1 = s1[i];
                    char2 = s2[i];
                }
            }
        }
        return count == 2 || count == 0;
    }
};