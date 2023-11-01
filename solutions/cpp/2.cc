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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = l1->val + l2->val;
        int carry = val / 10;
        ListNode *head = new ListNode(val%10);

        l1 = l1->next;
        l2 = l2->next;
        ListNode *tmp = head;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                val = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != nullptr) {
                val = l1->val + carry;
                l1 = l1->next;
            } else {
                val = l2->val + carry;
                l2 = l2->next;
            }

            carry = val / 10;
            tmp->next = new ListNode(val % 10);
            tmp = tmp->next;
        }

        if (carry != 0) {
            tmp->next = new ListNode(carry);
        }

        return head;
    }
};
