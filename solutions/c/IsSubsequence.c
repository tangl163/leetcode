bool
isSubsequence(char *s, char *t)
{
    int i, j, slen, tlen;

    slen = strlen(s);
    tlen = strlen(t);

    if (slen > tlen) {
        return false;
    }

    for (i = j = 0; i < tlen; i++) {
        if (j < slen && s[j] == t[i]) {
            j++;
        }
    }

    return j == slen;
}

