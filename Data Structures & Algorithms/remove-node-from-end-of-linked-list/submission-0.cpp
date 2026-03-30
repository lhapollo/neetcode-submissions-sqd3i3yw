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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
                int size = 0;
                ListNode* curr = head;
                while (curr) {
                        size++;
                        curr = curr->next;
                }

                int target = size - n + 1;

                // ✅ handle head deletion FIRST
                if (target == 1) {
                        return head->next;
                }

                curr = head;
                for (int i = 1; i < target - 1; i++) {
                        curr = curr->next;
                }

                curr->next = curr->next->next;
                return head;
        }

};
