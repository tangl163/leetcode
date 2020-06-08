static int *kmpAux(char *needle, int len);

int
strStr(char *haystack, char *needle)
{
    int i, j, len1, len2;
    int *t;

    len1 = strlen(haystack);
    len2 = strlen(needle);

    if (len2 == 0) {
        return 0;
    }

    t = kmpAux(needle, len2);

    for (i = j = 0; i < len1; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = t[j-1];
        }

        if (haystack[i] == needle[j]) {
            j++;
        }

        if (j == len2) {
            return i - j + 1;
        }
    }

    return -1;
}

static int *
kmpAux(char *needle, int len)
{
    int i, j;
    int *t;

    t = malloc(len * sizeof *t);
    assert(t != NULL);
    t[0] = 0;

    for (i = 1, j = 0; i < len; i++) {
        while (j > 0 && needle[i] != needle[j]) {
            j = t[j-1];
        }

        if (needle[i] == needle[j]) {
            t[i] = j++;
        }

        t[i] = j;
    }

    return t;
}

