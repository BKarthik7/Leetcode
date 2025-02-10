#include <stack>
#include <string>

class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <='9'){
                if(!stk.empty()) stk.pop();
            } else{
                stk.push(s[i]);
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};