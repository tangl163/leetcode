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
    struct ListNode *tmp, *dummyhead, *p;

    dummyhead = p = malloc(sizeof *dummyhead);
    dummyhead->next = tmp = head;

    for (step = 1; tmp; step++) {
        if (step > n)
            p = p->next;

        tmp = tmp->next;
    }

    tmp = p->next;

    if (tmp == head)
        head = tmp->next;
    else
        p->next = tmp->next;

    /* avoid memory leakage */
    free(tmp);
    free(dummyhead);

    return head;
}

