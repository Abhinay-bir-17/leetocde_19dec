class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        int cnt = 2;
        ListNode *temp = even->next;
        ListNode *last = even;
        while (temp != NULL) {
            // cout<<"temp->val:"<<temp->val<<endl;
            cnt += 1;
            if (cnt & 1) {
                odd->next = temp;
                odd = temp;
                temp = temp->next;
                odd->next = even;
            } else {
                last->next = temp;
                last = temp;
                temp = temp->next;
            }
            // cout<<"temp->val2:"<<temp->val<<endl;
        }
        last->next = NULL;
        return head;
    }
};