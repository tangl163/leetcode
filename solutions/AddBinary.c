char *
addBinary(char *a, char *b)
{
    char *p;
    int i, tmp, carry;
    int len, alen, blen;

    i = carry = 0;
    alen = strlen(a);
    blen = strlen(b);
    len = (alen > blen) ? (alen + 2) : (blen + 2);

    p = malloc(sizeof *p * len);

    for (alen -= 1, blen -= 1; alen >= 0 || blen >= 0; alen--, blen--) {
        if (alen >= 0 && blen >= 0) {
            tmp = a[alen] + b[blen] + carry;
        } else if (alen >= 0) {
            tmp = a[alen] + carry;
        } else {
            tmp = b[blen] + carry;
        }

        p[i++] = (tmp & 1) + '0';
        carry = (tmp & 2) >> 1;
    }

    if (carry)
        p[i++] = 49;

    p[i] = 0;

    for (alen = 0, blen = i - 1; alen < blen; alen++, blen--) {
        tmp = p[alen];
        p[alen] = p[blen];
        p[blen] = tmp;
    }

    return p;
}

