char *
addStrings(char *num1, char *num2)
{
    char *p;
    int len, len1, len2;
    int i, j, k, tmp, carry;

    len1 = strlen(num1);
    len2 = strlen(num2);

    k = carry = 0;
    len = (len1 > len2) ? (len1 + 2) : (len2 + 2);
    p = malloc(sizeof *p * len);

    for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--) {
        if (i >= 0 && j >= 0) {
            tmp = num1[i] + num2[j] + carry - 2 * '0';
        } else if (i >= 0) {
            tmp = num1[i] + carry - '0';
        } else {
            tmp = num2[j] + carry - '0';
        }

        if (tmp >= 10) {
            p[k++] = tmp + 38;
            carry = 1;
        } else {
            p[k++] = tmp + '0';
            carry = 0;
        }
    }

    if (carry)
        p[k++] = '1';

    p[k] = 0;

    for (i = 0, j = k - 1; i < j; i++, j--) {
        tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
    }

    return p;
}

