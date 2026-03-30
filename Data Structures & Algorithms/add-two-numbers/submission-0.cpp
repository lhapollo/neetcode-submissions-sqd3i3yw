class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev = nullptr;
        ListNode* ans = nullptr;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ListNode* digit = new ListNode(sum % 10);

            if (!ans) {
                ans = digit;          // first node
            } else {
                prev->next = digit;  // link
            }

            prev = digit;
        }

        return ans;
    }
};
