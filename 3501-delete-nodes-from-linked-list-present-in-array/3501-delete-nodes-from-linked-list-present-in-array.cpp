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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
        }
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        
        while(head != nullptr) {
            if(m.find(head->val) == m.end()) {
                ans->next = new ListNode(head->val);
                ans = ans->next;
            }
            head = head->next;
        }
        
        return dummy->next;
    }
};