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
    ListNode* reverse(ListNode* head){
        ListNode* dummy = NULL;
        while(head){
            ListNode* head_nxt = head->next;
            head->next = dummy;
            dummy = head;
            head = head_nxt;
        }
        
        return dummy;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL or head==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=nullptr and fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* reverse_head = reverse(slow);
        
        while(head and reverse_head){
            if(head->val!=reverse_head->val) return false;
            head = head->next;
            reverse_head = reverse_head->next;
        }
        return true;
    }
};