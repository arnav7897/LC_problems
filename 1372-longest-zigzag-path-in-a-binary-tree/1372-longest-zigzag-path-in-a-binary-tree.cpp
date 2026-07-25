class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, bool cameFromLeft, int len) {
        if (!root)
            return;

        ans = max(ans, len);

        if (cameFromLeft) {
            dfs(root->right, false, len + 1);
            dfs(root->left, true, 1);
        } else {
            dfs(root->left, true, len + 1);
            dfs(root->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root)
            return 0;

        dfs(root->left, true, 1);
        dfs(root->right, false, 1);

        return ans;
    }
};
