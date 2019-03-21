/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
plusOne(int *digits, int len, int *returnSize)
{
    int carry;
    int *p, i;

    p = malloc(sizeof *p * len);
    p[len-1] = digits[len-1] + 1;
    carry = p[len-1] == 10 ? 1 : 0;
    p[len-1] %= 10;

    for (i = len - 2; i >= 0; i--) {
        p[i] = digits[i] + carry;

        if (p[i] == 10) {
            carry = 1;
            p[i] = 0;
        } else {
            carry = 0;
        }
    }

    if (carry) {
        free(p);
        len += 1;
        p = malloc(sizeof *p * len);
        memset(p, 0, len);
        *p = 1;
    }

    *returnSize = len;

    return p;
}

