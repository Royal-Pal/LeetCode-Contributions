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
    TreeNode* rec(TreeNode* root1, TreeNode* root2, TreeNode* new_tree) {
        if(root1 == NULL && root2 == NULL) {
            return NULL;
        }
        
        if(root1 != NULL && root2 != NULL) {
            new_tree = new TreeNode(root1->val + root2->val);
            new_tree->left = rec(root1->left, root2->left, new_tree->left);
            new_tree->right = rec(root1->right, root2->right, new_tree->right);
        } else if(root1 == NULL) {
            new_tree = new TreeNode(root2->val);
            new_tree->left = rec(NULL, root2->left, new_tree->left);
            new_tree->right = rec(NULL, root2->right, new_tree->right);
        } else {
            new_tree = new TreeNode(root1->val);
            new_tree->left = rec(root1->left, NULL, new_tree->left);
            new_tree->right = rec(root1->right, NULL, new_tree->right);
        }
        
        return new_tree;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 == NULL) {
            if(root1 == NULL && root2 == NULL) {
                return NULL;
            } else if(root1 == NULL) {
                return root2;
            } else {
                return root1;
            }
        }
        
        TreeNode* new_tree = new TreeNode();
        return rec(root1, root2, new_tree);
    }
};