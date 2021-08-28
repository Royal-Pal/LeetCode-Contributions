/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return NULL;
        }
        if(root == p || root == q) {
            return root;
        }
        
        TreeNode* lca = lowestCommonAncestor(root->left, p, q);
        TreeNode* rca = lowestCommonAncestor(root->right, p, q);
        
        if(!lca || !rca) {
            if(!lca && !rca) {
                return NULL;
            } else if(!lca) {
                return rca;
            } else {
                return lca;
            }
        } else {
            return root;
        }
    }
};