/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool
hasCycle(struct ListNode *head)
{
    struct ListNode *slowPtr, *fastPtr;

    slowPtr = fastPtr = head;

    while (slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr)
            return 1;
    }

    return 0;
}

