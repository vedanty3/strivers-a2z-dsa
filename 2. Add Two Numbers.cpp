class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head  = new ListNode(0);
        ListNode* temp = head;
        
        int carry = 0;
        
        while(l1 or l2) {
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            
            int last_digit = sum%10;
            
            temp->next = new ListNode(last_digit);
            temp = temp->next;
            
            carry = sum/10;
        }
        
        if(carry) {
            temp->next = new ListNode(carry);
        }
        
        return head->next;
    }
};
