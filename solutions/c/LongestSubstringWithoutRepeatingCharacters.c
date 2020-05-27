static int findIndex(char *, int, int, char);

int
lengthOfLongestSubstring(char *s)
{
    int i, j, len, max, idx;

    max = 0;
    len = strlen(s);

    for (i = 0, j = 0; j < len; j++) {
        idx = findIndex(s, i, j, s[j]);
        if (idx != -1 && idx > i) {
            i = idx;
        }

        if (j - i + 1 > max) {
            max = j - i + 1;
        }
    }

    return max;
}

static int
findIndex(char *s, int start, int end, char c)
{
    int i;

    for (i = start; i < end; i++) {
        if (s[i] == c) {
            return i + 1;
        }
    }

    return -1;
}

