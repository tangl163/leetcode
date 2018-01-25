/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
reverseList(struct ListNode *head)
{
    struct ListNode *pre, *current, *next;

    pre = next = NULL;
    current = head;

    while (current) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }

    return pre;
}

