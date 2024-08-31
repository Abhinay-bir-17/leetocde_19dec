// brute force soln
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {

		unordered_map<ListNode*, int> mp;
		while (head != NULL) {
			if (mp[head]) {return head;}
			else mp[head] = 1;
			head = head->next;
		} return NULL;
	}
};

// constant s.c
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		// focus abhinay bir you can do it, dont give up bro
		ListNode *temp = head;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next; fast = fast->next->next;
			if (slow == fast) {
				slow = head;
				while (slow != fast) {slow = slow->next; fast = fast->next;}
				return slow;
			}
		} return NULL;
	}
};