/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
deleteDuplicates(struct ListNode *head)
{
    struct ListNode prehead, *p;

    prehead.next = head;

    while (head && head->next) {
        if (head->val == head->next->val) {
            p = head->next;
            head->next = p->next;
            free(p);
        } else {
            head = head->next;
        }
    }

    return prehead.next;
}

