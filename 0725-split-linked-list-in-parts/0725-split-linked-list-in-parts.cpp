class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        ListNode* temp = head;
        int c = 0;
        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }
        int partSize = c / k;
        int remainder = c % k;
        ListNode* current = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < k && current != nullptr; i++) {
            ans[i] = current; 
            int currentPartSize = partSize + (i < remainder ? 1 : 0); 
            for (int j = 0; j < currentPartSize; j++) {
                prev = current;
                current = current->next;
            }
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }
        
        return ans;
    }
};
