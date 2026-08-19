class Solution {
public:
    int height(TreeNode* root, int* ans) {

        if (!root) {
            return 0;
        }

        int left = height(root->left, ans);
        int right = height(root->right, ans);

        int temp = 1+max(left , right);
        int res = max(temp , left + right +1);
        *ans = max(*ans, res);
        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int ans = INT_MIN;

        height(root, &ans);

        return ans-1;
    }
};