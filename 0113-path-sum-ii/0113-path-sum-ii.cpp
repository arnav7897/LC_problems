/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<vector<int>> &ans, vector<int> arr,int t){
        if(root == NULL){
            return ;
        }
        arr.push_back(root->val);
        t -= root->val;
        if(root->left == NULL && root->right == NULL && t == 0){
            ans.push_back(arr);
            return;
        }

        solve(root->left , ans , arr , t);
        solve(root->right , ans , arr , t);
    }

    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(root , ans , arr , t);
        return ans;
    }
};