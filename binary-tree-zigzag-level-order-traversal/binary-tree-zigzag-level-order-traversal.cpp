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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > trav;
        
        if(root == NULL) {
            return trav;
        }
        
        stack<TreeNode*> main_stack, child_stack;
        main_stack.push(root);
        
        bool ltr = true;
        
        while(!main_stack.empty() || !child_stack.empty()) {
            vector<int> curr;
            
            if(ltr) {
                while(!main_stack.empty()) {
                    curr.push_back(main_stack.top()->val);
                    
                    if(main_stack.top()->left) {
                        child_stack.push(main_stack.top()->left);
                    }
                    if(main_stack.top()->right) {
                        child_stack.push(main_stack.top()->right);
                    }
                    
                    main_stack.pop();
                }
            } else {
                while(!main_stack.empty()) {
                    curr.push_back(main_stack.top()->val);
                    
                    if(main_stack.top()->right) {
                        child_stack.push(main_stack.top()->right);
                    }
                    if(main_stack.top()->left) {
                        child_stack.push(main_stack.top()->left);
                    }
                    
                    main_stack.pop();
                }
            }
            
            swap(main_stack, child_stack);
            
            trav.push_back(curr);
            ltr = !ltr;
        }
        
        return trav;
    }
};