#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stk;
        int i = 0;

        while (i < traversal.size()) {
            int depth = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }

            int val = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            if (depth == stk.size()) {
                if (!stk.empty()) {
                    if (!stk.top()->left) {
                        stk.top()->left = node;
                    } else {
                        stk.top()->right = node;
                    }
                }
            } else {
                while (stk.size() > depth) {
                    stk.pop();
                }
                stk.top()->right = node;
            }

            stk.push(node);
        }

        while (stk.size() > 1) {
            stk.pop();
        }

        return stk.top();
    }
};