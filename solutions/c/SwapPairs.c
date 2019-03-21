/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
swapPairs(struct ListNode *head)
{
    struct ListNode prehead;
    struct ListNode *tmp, *dummyhead;

    prehead.next = head;
    dummyhead = &prehead;

    while (dummyhead->next && dummyhead->next->next) {
        tmp = dummyhead->next;
        dummyhead->next = tmp->next;
        tmp->next = tmp->next->next;
        dummyhead->next->next = tmp;
        dummyhead = tmp;
    }

    return prehead.next;
}

