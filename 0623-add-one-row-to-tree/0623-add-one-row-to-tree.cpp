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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* n1 = new TreeNode(val);
            n1->left = root;
            return n1;
        }
        if(root==NULL){
            return NULL;
        }
        queue<pair<int , TreeNode*>> q;
        q.push({1, root});
        while(!q.empty()){
            auto [d, node] = q.front();
            q.pop();
            if(d >= depth){
                break;
            }else if( d == depth -1){
                TreeNode* n1 = new TreeNode(val);
                TreeNode* n2 = new TreeNode(val);
                n1->left = node->left;
                n2->right = node->right;
                node->left = n1;
                node->right = n2;
            }else{
                if(node->left){
                    q.push({d+1, node->left});
                }
                if(node->right){
                    q.push({d+1, node->right});
                }
            }
        
        }
        return root;
    }
};