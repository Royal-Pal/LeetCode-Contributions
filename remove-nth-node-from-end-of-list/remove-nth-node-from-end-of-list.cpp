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
    int LLLen(ListNode* head) {
        int cnt = 0;
        while(head != NULL) {
            cnt++;
            head = head->next;
        }
        
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = LLLen(head);
        // cout << len << "\n";
        
        if(len == 1) {
            return NULL;
        }
        if(len == n) {
            return head->next;
        }
        
        n = len - n;
        // cout << n << "\n";
        
        ListNode* tmp = head;
        int cnt = 1;
        while(cnt < n) {
            tmp = tmp->next;
            cnt++;
        }
        // cout << tmp->val << "\n";
        
        tmp->next = tmp->next->next;
        
        return head;
    }
};