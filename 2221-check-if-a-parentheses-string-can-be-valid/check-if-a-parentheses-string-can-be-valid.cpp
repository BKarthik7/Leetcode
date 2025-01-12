class Solution {
public:
    bool canBeValid(string s, string lock) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        int open = 0, unlock = 0;
        for (int i = 0; i < n; i++) {
            if (lock[i] == '0') {
                unlock++;
            } else if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                if (open > 0) {
                    open--;
                } else if (unlock > 0) {
                    unlock--;
                } else {
                    return false;
                }
            }
        }
        int balance = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (lock[i] == '0') {
                balance--;
                unlock--;
            } else if (s[i] == '(') {
                balance++;
                open--;
            } else if (s[i] == ')') {
                balance--;
            }
            if (balance > 0) {
                return false;
            }
            if (unlock == 0 and open == 0) {
                break;
            }
        }

        if (open > 0) {
            return false;
        }

        return true;
    }
};