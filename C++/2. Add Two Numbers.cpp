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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        int carry = 0;

        while (l1 or l2 or carry)
        {
            int summ = 0;
            if (l1)
            {
                summ += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                summ += l2->val;
                l2 = l2->next;
            }

            summ += carry;
            carry = summ / 10;
            summ %= 10;
            tmp->next = new ListNode(summ);
            tmp = tmp->next;
        }

        return head->next;
    }
};