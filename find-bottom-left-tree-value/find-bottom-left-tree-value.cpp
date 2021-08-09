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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));
        
        int max_level = 1, leftmost_val = root->val;
        
        while(!q.empty()) {
            TreeNode* curr_node = q.front().first;
            int curr_level = q.front().second;
            q.pop();
            
            if(curr_level > max_level) {
                leftmost_val = curr_node->val;
                max_level = curr_level;
            }
            
            if(curr_node->left != NULL) {
                q.push(make_pair(curr_node->left, curr_level + 1));
            }
            if(curr_node->right != NULL) {
                q.push(make_pair(curr_node->right, curr_level + 1));
            }
        }
        
        return leftmost_val;
    }
};