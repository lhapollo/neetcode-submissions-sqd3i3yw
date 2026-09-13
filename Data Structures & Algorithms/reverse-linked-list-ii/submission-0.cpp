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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int ind = 1; 

        ListNode* sentinel = new ListNode();
        sentinel->next = head; 

        ListNode* curr = head; 
        ListNode* prev = sentinel; 

        ListNode* prevOfLeft = nullptr; 
        ListNode* leftNode = nullptr; 
        ListNode* rightNode = nullptr; 

        while (ind <= right) {
            ListNode* temp = curr->next; 
            if (ind == left) {
                prevOfLeft = prev;
                leftNode = curr; 
            } else if (ind > left && ind < right) {
                //reverse
                curr->next = prev; 
            } else if (ind == right) {
                rightNode = curr; 
                leftNode->next = curr->next; 
                curr->next = prev; 
                prevOfLeft->next = curr; 
            }
            
            //increment ind
            prev = curr; 
            curr = temp;
            ind++;
        }
  
        return sentinel->next; 

        //connect leftNode->next = oldRightNode->next
    }
};