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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next;
        ListNode* curr = head->next;
        int currentSum = 0;
        while(curr !=nullptr){
            if(curr->val != 0){
                currentSum += curr->val;
            }
            else {
                modify->val = currentSum;
                currentSum =0;
                 modify->next = curr->next;
                 modify = modify->next;
            }
            curr = curr->next;
        }
            
            
        
        return head->next;
        
    }
};