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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
   
       if(root == NULL) {
           return view;
       }

       queue<pair<TreeNode*, int> > q;
       q.push(make_pair(root, 1));

       while(!q.empty()) {
           TreeNode* curr_node = q.front().first;
           int curr_level = q.front().second;
           q.pop();

           if(view.size() < curr_level) {
               view.push_back(curr_node->val);
           }
           
           if(curr_node->right != NULL) {
               q.push(make_pair(curr_node->right, curr_level + 1));
           }
           if(curr_node->left != NULL) {
               q.push(make_pair(curr_node->left, curr_level + 1));
           }
       }

       return view;
    }
};