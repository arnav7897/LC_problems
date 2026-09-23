class Solution {
public:

    TreeNode* solve(vector<TreeNode*>& ans, TreeNode* root, unordered_set<int>& s) {
        if (root == NULL) {
            return NULL;
        }

        root->left = solve(ans, root->left, s);
        root->right = solve(ans, root->right, s);

        if (s.find(root->val) != s.end()) {

            if (root->left) {
                ans.push_back(root->left);
            }

            if (root->right) {
                ans.push_back(root->right);
            }

            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> s;

        for (auto &it : to_delete) {
            s.insert(it);
        }

        root = solve(ans, root, s);

        if (root) {
            ans.push_back(root);
        }

        return ans;
    }
};