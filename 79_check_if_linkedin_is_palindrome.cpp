//brute force
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp = new ListNode(head->val);
        ListNode *itr = head;
        itr = itr->next;
        while (itr != NULL) {
            ListNode *t = new ListNode(itr->val);
            t->next = temp;
            temp = t; itr = itr->next;
        }
        while (head != NULL &&  temp != NULL) {
            if (head->val != temp->val)return false;
            head =  head->next; temp = temp->next;
        }
        if (head != NULL || temp != NULL)return false;
        return true;
    }
};

// O(n) t.c with constant space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL)return true;
        ListNode * slow = head; ListNode*fast = head; ListNode * prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = head->next;
            head->next = prev;
            prev = head;
            head = slow;
        }
        if (fast == NULL) {

        }   else {
            slow = slow->next;
        }
        while (slow != NULL && prev != NULL) {
            if (slow->val != prev->val)break;
            slow = slow->next; prev = prev->next;
        }
        if (slow != NULL || prev != NULL)return false;
        else return true;

    }
};