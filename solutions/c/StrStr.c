int
strStr(char* haystack, char* needle)
{
    int i, j;
    char *p1, *p2;

    if (*needle == NULL)
        return 0;

    for (p1 = haystack; *p1; p1++) {
        for (p2 = needle, i = 0; p1[i] && p2[i]; i++) {
            if (p1[i] != p2[i])
                break;
        }

        if (p2[i] == NULL)
            break;
    }

    return *p1 ? p1 - haystack : -1;
}

