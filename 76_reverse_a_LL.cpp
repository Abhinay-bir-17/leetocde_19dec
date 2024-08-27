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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) {return head;}
		if (head->next == NULL) {return head;}
		ListNode *temp = new ListNode(head->val);
		head = head->next;
		while (head) {
			ListNode *aux = new ListNode(head->val, temp);
			temp = aux; head = head->next;
		}
		head = temp; return head;
	}
};