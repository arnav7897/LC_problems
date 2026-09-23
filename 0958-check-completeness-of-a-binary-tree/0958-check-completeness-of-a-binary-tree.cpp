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
    bool isCompleteTree(TreeNode* root) {
        bool ans = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            if(a == NULL){
                ans = true;
                continue;
            }
            if(ans){
                return false; 
            }
            q.push(a->left);
            q.push(a->right);
        }         
        return true;
    }
};