class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			if(!list1) {
				return list2;
			} else if(!list2) {
				return list1;
			}

			if(list1->val>list2->val) {
				swap(list1, list2);
			}

			ListNode* head = list1;

			while(list1 and list2) {
				ListNode* tmp;
				while(list1 and list1->val<=list2->val) {
					tmp = list1;
					list1 = list1->next;
				}
				tmp->next = list2;
				swap(list1, list2);
			}

			return head;
		}
};
