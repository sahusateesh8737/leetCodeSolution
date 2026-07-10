/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;   // Link to list1 node
                list1 = list1->next;  // Move list1 forward
            } else {
                tail->next = list2;   // Link to list2 node
                list2 = list2->next;  // Move list2 forward
            }
            tail = tail->next;        // Move tail forward
        }

        // If one list is not empty, attach the rest of it
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the actual head (next node after dummy)
        return dummy.next;
    }
};