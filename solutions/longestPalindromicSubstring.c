char *
longestPalindrome(char *s)
{
    int d, i, j, k;
    int n, found, len, start, maxlen;
    char *ret;

    start = 0;
    maxlen = 1;
    len = strlen(s);

    for (i = 0; i < len; i++) {
        n = found = 0;

        for (j = len-1; j > i; j--) {
            for (d = i, k = j; d < k; d++, k--) {
                if (s[d] != s[k])
                    break;
            }

            if (d >= k) {
                found = 1;
                n = j - i + 1;
                break;
            }
        }

        if (found && maxlen < n) {
            start = i;
            maxlen = n;
        }

        if (len - i <= maxlen)
            break;
    }

    ret = malloc(sizeof *s * (maxlen + 1));
    strncpy(ret, &s[start], maxlen);
    ret[maxlen] = 0;

    return ret;
}

