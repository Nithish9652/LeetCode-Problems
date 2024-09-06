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
   bool checkElement(vector<int>& nums,int target){
    int s=0;
    int e=nums.size()-1;
    int mid=(s+e)/2;
    while(s<e){
        if(nums[mid] == target) return true;
        else if(nums[mid] < target){
            s=mid+1;

        }
        else if(nums[mid] > target){
            e=mid-1;
            
        }
        mid=(s+e)/2;
    }
    if(nums[s] == target) return true;
    
    return false;


   }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode*dummy= new ListNode(-1);
        ListNode* prev=dummy;
        dummy->next = head;
        sort(nums.begin(),nums.end());
        while(head){
            ListNode* next = head->next;
            bool ans = checkElement(nums,head->val);
            if(ans){
                prev->next = head->next;
            }
            else{
                prev=head;
            }
            head=next;


        }
        return dummy->next; 
        
    }
};