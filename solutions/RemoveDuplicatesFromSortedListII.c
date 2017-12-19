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
    int flag = 0;
    struct ListNode prehead, *p, *tmp;

    prehead.next = head;
    tmp = &prehead;

    while (head && head->next) {

        if (head->val == head->next->val) {
            p = head->next;
            head->next = p->next;
            free(p);
            flag = 1;
        } else if (flag) {
            p = head;
            head = head->next;
            tmp->next = head;
            free(p);
            flag = 0;
        } else {
            tmp = tmp->next;
            head = head->next;
        }
    }

    if (flag) {
        p = tmp->next;
        tmp->next = p->next;
        free(p);
    }

    return prehead.next;
}

