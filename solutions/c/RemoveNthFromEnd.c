/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
removeNthFromEnd(struct ListNode *head, int n)
{
    int step;
    struct ListNode prehead;
    struct ListNode *tmp, *p;

    p = &prehead;
    prehead.next = head;

    for (step = 1; head; step++) {
        if (step > n)
            p = p->next;

        head = head->next;
    }

    tmp = p->next;
    p->next = tmp->next;
    free(tmp);

    return prehead.next;
}

