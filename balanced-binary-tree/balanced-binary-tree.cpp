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
    #define mp make_pair
    #define ff first
    #define ss second
    
public:
    pair<int, bool> rec(TreeNode* root) {
        if(root == NULL) {
            return mp(0, true);
        }
        
        pair<int, bool> ls = rec(root->left);
        pair<int, bool> rs = rec(root->right);
        
        return mp(1 + max(ls.ff, rs.ff),
                  ((abs(ls.ff - rs.ff) <= 1) && (ls.ss && rs.ss)));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        return rec(root).ss;
    }
};