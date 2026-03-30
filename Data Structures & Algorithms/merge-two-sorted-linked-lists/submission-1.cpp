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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list1_curr = list1;
        ListNode* list2_curr = list2;
        ListNode* curr; 
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1; 

        if (list1_curr->val <= list2_curr->val) {
            curr = list1_curr; 
            list1_curr = list1_curr->next; 
        } else {
            curr = list2_curr; 
            list2_curr = list2_curr->next; 
        }

        while (list1_curr != nullptr || list2_curr != nullptr) {
           if (list1_curr == nullptr || (list2_curr != nullptr && list2_curr->val <= list1_curr->val)) {
                curr->next = list2_curr;
                list2_curr = list2_curr->next;
            } else {
                curr->next = list1_curr;
                list1_curr = list1_curr->next;
            }
            curr = curr->next;
        }

        if (list1->val <= list2->val) return list1;
        else return list2;
    }
};
