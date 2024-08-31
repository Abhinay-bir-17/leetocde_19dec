// my solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int f;
        if (head == NULL)return false;
        while (1) {
            if (head->next == NULL) {f = 1; break;}
            if (head->next->val == INT_MIN) {f = 0; break;}
            else head->val = INT_MIN;
            head = head->next;

        }
        if (f)return false; else return true;
    }
};
// slow and fast method
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)return 0;
        if (head->next == NULL)return 0;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; fast = fast->next->next;
            if (slow == fast)return true;
        } return false;
    }
};