class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			ListNode* l1 = headA;
			ListNode* l2 = headB;

			while(1) {
				if(l1==l2) {
					return l1;
				}

				if(l1==nullptr) {
					l1 = headB;
				} else {
					l1 = l1->next;
				}

				if(l2==nullptr) {
					l2 = headA;
				} else {
					l2 = l2->next;
				}
			}

			return nullptr;
		}
};

