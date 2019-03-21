int
lengthOfLongestSubstring(char *s)
{
    int i, j, k;
    int n, repeat, len, maxlen;

    n = maxlen = 0;
    len = strlen(s);

    for (i = 0; i < len; i++) {
        n = 1;
        repeat = 0;

        for (j = i+1; j < len && !repeat; j++) {
            for (k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    repeat = 1;
                    break;
                }
            }

            if (!repeat)
                n++;
        }

        if (n > maxlen)
            maxlen = n;

        if (len - i < maxlen)
            break;
    }

    return maxlen;
}

