char *
reverseString(char *s)
{
    char tmp;
    int i, j, len;

    len = strlen(s);

    for (i = 0, j = len-1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    return s;
}

