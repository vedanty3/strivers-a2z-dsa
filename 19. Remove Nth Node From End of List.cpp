class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			int len = 0;
			ListNode* tmp = head;

			while(tmp) {
				tmp = tmp->next;
				++len;
			}

			if(n==len) {
				ListNode* del_node = head;
				head = head->next;
				delete del_node;
				return head;
			}

			int k = len - n - 1;
			tmp = head;

			while(k) {
				tmp = tmp->next;
				--k;
			}

			ListNode* del_node = tmp->next;
			tmp->next = tmp->next->next;
			delete del_node;
			return head;
		}
};

class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			ListNode* slo = dummy;
			ListNode* fast = dummy;

			while(n) {
				fast = fast->next;
				--n;
			}

			while(fast->next) {
				slo = slo->next;
				fast = fast->next;
			}

			ListNode* del_node = slo->next;
			slo->next = slo->next->next;
			delete del_node;
			return dummy->next;
		}
};


