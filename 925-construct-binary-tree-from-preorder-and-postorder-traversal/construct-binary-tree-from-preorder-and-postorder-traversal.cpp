class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); ++i) {
            postIndex[postorder[i]] = i;
        }
        return construct(preorder, postorder, 0, 0, preorder.size(), postIndex);
    }

private:
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int preStart, int postStart, int size, unordered_map<int, int>& postIndex) {
        if (size == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (size == 1) return root;

        int leftChild = preorder[preStart + 1];
        int leftSize = postIndex[leftChild] - postStart + 1;

        root->left = construct(preorder, postorder, preStart + 1, postStart, leftSize, postIndex);
        root->right = construct(preorder, postorder, preStart + 1 + leftSize, postStart + leftSize, size - 1 - leftSize, postIndex);

        return root;
    }
};

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> currentLevel = {root};
    while (!currentLevel.empty()) {
        vector<TreeNode*> nextLevel;
        for (TreeNode* node : currentLevel) {
            if (node) {
                cout << node->val << " ";
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            } else {
                cout << "null ";
                nextLevel.push_back(nullptr);
                nextLevel.push_back(nullptr);
            }
        }
        cout << endl;
        currentLevel = nextLevel;
    }
}