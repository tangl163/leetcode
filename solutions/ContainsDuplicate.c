#define NUMS 29

struct Bucket {
    int val;
    struct Bucket *next;
};

bool
containsDuplicate(int *nums, int len)
{
    int i, hash;
    struct Bucket *table[NUMS], *p, *tmp;

    memset(table, 0, sizeof table);

    for (i = 0; i < len; i++) {
        hash = ((unsigned)nums[i]) % NUMS;
        p = table[hash];

        while (p) {
            if (p->val == nums[i])
                return 1;
            else
                p = p->next;
        }

        p = malloc(sizeof *p);
        p->val = nums[i];
        p->next = table[hash];
        table[hash] = p;
    }

    /* call free to avoid memory leakage */
    for (i = 0; i < NUMS; i++) {
        p = table[i];
        while (p) {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }

    return 0;

success:

    /* call free to avoid memory leakage */
    for (i = 0; i < NUMS; i++) {
        p = table[i];
        while (p) {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }

    return 1;
}

