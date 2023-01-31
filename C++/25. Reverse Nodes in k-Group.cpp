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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head or !head->next)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = dummy;
        ListNode *nxt = dummy;
        int cnt = 0;
        while (curr->next)
        {
            cnt++;
            curr = curr->next;
        }

        while (cnt >= k)
        {
            curr = prev->next;
            nxt = curr->next;
            for (int i = 0; i < k - 1; ++i)
            {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            cnt -= k;
        }

        return dummy->next;
    }
};