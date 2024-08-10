class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int n = 1;
        while (temp->next != nullptr) {
            n++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % n; 
        int breakPoint = n - k; 
        ListNode* newTail = head;
        for (int i = 1; i < breakPoint; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};