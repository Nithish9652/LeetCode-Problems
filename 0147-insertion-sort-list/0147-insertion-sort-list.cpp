class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1); // sorted list starts here

        while (head) {
            ListNode* cur = head;      // take one node
            head = head->next;         // move input list

            // find position to insert in sorted list
            ListNode* temp = dummy;
            while (temp->next && temp->next->val < cur->val) {
                temp = temp->next;
            }

            // insert cur between temp and temp->next
            cur->next = temp->next;
            temp->next = cur;
        }

        return dummy->next;
    }
};
