bool
isMatch(char *s, char *p)
{
    bool sign;
    int slen, plen;

    sign = false;
    slen = strlen(s);
    plen = strlen(p);

    if (plen == 0) {
        return slen == 0;
    }

    if (slen != 0 && (s[0] == p[0] || p[0] == '.')) {
        sign = true;
    }

    if (plen >= 2 && p[1] == '*') {
        return sign && isMatch(s+1, p) || isMatch(s, p+2);
    }

    return sign && isMatch(s+1, p+1);
}

