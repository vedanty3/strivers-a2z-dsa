class Solution {
	public:
		bool hasCycle(ListNode *head) {
			ListNode* fast = head;
			ListNode* slo = head;

			while(fast and slo and fast->next) {
				slo = slo->next;
				fast = fast->next->next;

				if(slo==fast) {
					return true;
				}
			}

			return false;
		}
};
