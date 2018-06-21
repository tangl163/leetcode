/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
insertionSortList(struct ListNode *head)
{
    struct ListNode dummyHead = {0};
    struct ListNode *cur, *next, *pre;

    pre = &dummyHead;
    cur = head;

    while (cur != NULL) {
        next = cur->next;

        while (pre->next && pre->next->val < cur->val)
            pre = pre->next;

        cur->next = pre->next;
        pre->next = cur;
        pre = &dummyHead;
        cur = next;
    }

    return dummyHead.next;
}

