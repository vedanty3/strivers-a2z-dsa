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

// Approach 1 (Two passes)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = 0;
        ListNode *tmp = head;
        ListNode *curr = head;
        while (tmp)
        {
            length++;
            tmp = tmp->next;
        }

        if (length == n)
            return head->next;
        n = length - n;

        while (--n)
        {
            curr = curr->next;
        }

        ListNode *free = curr->next;
        curr->next = curr->next->next;
        delete free;
        return head;
    }
};

// Approach 2 (Single pass)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (n)
        {
            fast = fast->next;
            n--;
        }

        if (fast == NULL)
            return slow->next;

        while (fast and fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};