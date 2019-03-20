char *
longestCommonPrefix(char **strs, int strsSize)
{
    char *p;
    int i, j;

    if (strsSize == 0)
        return "";

    i = 0;

    while (strs[0][i]) {
        for (j = 1; j < strsSize; j++) {
            if (strs[0][i] != strs[j][i])
                break;
        }

        if (j != strsSize)
            break;

        i++;
    }

    p = malloc(sizeof *p * (i + 1));
    for (j = 0; j < i; j++)
        p[j] = strs[0][j];

    p[i] = 0;

    return p;
}

