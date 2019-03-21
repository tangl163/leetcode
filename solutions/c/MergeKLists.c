static int listsIsEmpty(struct ListNode **lists, int listsSize);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
mergeKLists(struct ListNode **lists, int listsSize)
{
    int i, minIndex, minVal;
    struct ListNode prehead, *dummyhead;

    prehead.next = NULL;
    dummyhead = &prehead;

    while (!listsIsEmpty(lists, listsSize)) {

        for (i = 0; i < listsSize; i++) {
            if (lists[i]) {
                minIndex = i;
                minVal = lists[i]->val;
                break;
            }
        }

        for (i = i + 1; i < listsSize; i++) {
            if (lists[i] && lists[i]->val < minVal) {
                minIndex = i;
                minVal = lists[i]->val;
            }
        }

        dummyhead->next = lists[minIndex];
        dummyhead = dummyhead->next;
        lists[minIndex] = lists[minIndex]->next;
    }

    return prehead.next;
}

static int
listsIsEmpty(struct ListNode **lists, int listsSize)
{
    int i;

    for (i = 0; i < listsSize; i++) {
        if (lists[i])
            return 0;
    }

    return 1;
}

