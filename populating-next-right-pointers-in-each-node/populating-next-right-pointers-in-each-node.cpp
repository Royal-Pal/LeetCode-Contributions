/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    #define mp make_pair
    #define ff first
    #define ss second
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return root;
        }
        
        queue<pair<Node*, int> > q;
        q.push(mp(root, 1));
        
        while(!q.empty()) {
            Node* curr = q.front().ff;
            int level = q.front().ss;
            
            q.pop();
            
            if(q.empty() || (q.front().ss != level)) {
                curr->next = NULL;
            } else {
                curr->next = q.front().ff;
            }
            
            if(curr->left) {
                q.push(mp(curr->left, level + 1));
            }
            if(curr->right) {
                q.push(mp(curr->right, level + 1));
            }
        }
        
        return root;
    }
};