static struct ListNode *createNode(int val);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *
addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    unsigned int carry, sum;
    struct ListNode *head, *dummyhead, *node1, *node2;

    carry = 0;

    sum = l1->val + l2->val;
    if (sum >= 10) {
        carry = 1;
        sum -= 10;
    }

    head = dummyhead = createNode(sum);

    node1 = l1->next;
    node2 = l2->next;

    while (node1 || node2) {
        if (node1 && node2) {
            sum = node1->val + node2->val + carry;
            node1 = node1->next;
            node2 = node2->next;

        } else if (node1) {
            sum = node1->val + carry;
            node1 = node1->next;

        } else {
            sum = node2->val + carry;
            node2 = node2->next;
        }

        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        dummyhead->next = createNode(sum);
        dummyhead = dummyhead->next;
    }

    if (carry)
        dummyhead->next = createNode(carry);

    return head;
}

static struct ListNode *
createNode(int val)
{
    struct ListNode *p;

    p = malloc(sizeof *p);
    p->val = val;
    p->next = NULL;

    return p;
}

