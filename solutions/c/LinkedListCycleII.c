/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
detectCycle(struct ListNode *head)
{
    int hasCycle = 0;
    struct ListNode *slowPtr, *fastPtr;

    slowPtr = fastPtr = head;

    while (slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
            hasCycle = 1;
            break;
        }
    }

    if (!hasCycle)
        return NULL;

    slowPtr = head;

    while (slowPtr != fastPtr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    return slowPtr;
}

