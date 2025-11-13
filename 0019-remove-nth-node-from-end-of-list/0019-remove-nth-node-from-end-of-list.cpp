class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 0;
        ListNode* temp = head;
        while (temp) {
            c++;
            temp = temp->next;
        }
        n = c - n;
        c = 0;
        if (n == 0) {
            return head->next;
        }
        ListNode* temp2 = head;
        while (c < n - 1) {
            c++;
            temp2 = temp2->next;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};
