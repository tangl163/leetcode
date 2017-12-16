/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode prehead;
    struct ListNode *p;

    p = &prehead;

    while (l1 && l2) {

        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }

        p = p->next;
    }

    p->next = l1 ? l1 : l2;

    return prehead.next;
}

