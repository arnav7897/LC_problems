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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<TreeNode *,int>> q;
        q.push({root , 0});
        while(!q.empty()){
            auto [a,b] = q.front();
            if(ans.size() > b){
                ans[b].push_back(a->val);
            }else{
                ans.push_back({a->val});
            }
            q.pop();
            if(a->left){
                q.push({a->left , b+1});
            }
            if(a->right){
                q.push({a->right , b+1});
            }
        } 
        return ans;
    }
};