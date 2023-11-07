static struct ListNode *
mergeList(struct ListNode *l1, struct ListNode *l2);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *
sortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *slow, *fast, *tmp;
    tmp = slow = fast = head;

    while (fast != NULL && fast->next != NULL) {
        tmp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    tmp->next = NULL;

    struct ListNode *l1 = sortList(head);
    struct ListNode *l2 = sortList(slow);

    return mergeList(l1, l2);
}

struct ListNode *
mergeList(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode dummy;
    struct ListNode *tail = &dummy;

    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            tail->next = l2;
            break;
        } else if (l2 == NULL) {
            tail->next = l1;
            break;
        } else {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }
    }

    return dummy.next;
}
