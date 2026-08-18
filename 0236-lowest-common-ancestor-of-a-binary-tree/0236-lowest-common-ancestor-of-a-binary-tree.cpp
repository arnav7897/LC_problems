class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* qu) {

        if(root == NULL) {
            return NULL;
        }

        if(root == p || root == qu) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, qu);
        TreeNode* right = lowestCommonAncestor(root->right, p, qu);

        if(left != NULL && right != NULL) {
            return root;
        }

        if(left != NULL) {
            return left;
        }

        return right;
    }
};