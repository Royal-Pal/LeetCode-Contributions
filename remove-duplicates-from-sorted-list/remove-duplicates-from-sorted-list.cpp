/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        
        ListNode* tmp1 = head;
        
        while(tmp1 != NULL) {
            ListNode* tmp2 = tmp1->next;
            
            while(tmp2 != NULL && tmp2->val == tmp1->val) {
                tmp2 = tmp2->next;
            }
            
            tmp1->next = tmp2;
            tmp1 = tmp1->next;
        }
        
        return head;
    }
};