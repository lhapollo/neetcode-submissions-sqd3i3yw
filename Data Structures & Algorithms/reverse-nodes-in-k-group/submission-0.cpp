class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: check if we have k nodes
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head;  // not enough nodes
            curr = curr->next;
        }

        // Step 2: reverse k nodes
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Step 3: recurse on remaining list
        head->next = reverseKGroup(curr, k);

        // Step 4: prev is new head
        return prev;
    }
};
