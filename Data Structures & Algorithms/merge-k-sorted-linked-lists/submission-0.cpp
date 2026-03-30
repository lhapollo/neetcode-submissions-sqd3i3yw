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
    //returns head of merged list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2; 
        if (l2 == nullptr) return l1; 
        ListNode* ans; 
        ListNode* curr; 
        if (l1->val <= l2->val) {
            curr = l1;
            ans = l1;
            l1 = l1->next; 
        } else {
            curr = l2; 
            ans = l2; 
            l2 = l2->next;
        }
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr || (l2 != nullptr && l2->val <= l1->val)) {
                curr->next = l2; 
                l2 = l2->next; 
            } else {
                curr->next = l1; 
                l1 = l1->next; 
            }
            curr = curr->next; 
        }
        return ans; 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr; 
        for (int i = 1; i < lists.size(); i++) {
            ListNode* merged = mergeTwoLists(lists[i-1], lists[i]); 
            lists[i] = merged; 
        }
        return lists[lists.size()-1];
    }
};
