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

    if (slen != 0 && (p[0] == '.' || s[0] == p[0])) {
        sign = true;
    }

    if (plen >= 2 && p[1] == '*') {
        return sign && isMatch(s+1, p) || isMatch(s, p+2);
    }

    return sign && isMatch(s+1, p+1);
}

bool
isMatchDPTopDown(char *s, char *p)
{
    int slen, plen;

    slen = strlen(s);
    plen = strlen(p);

    bool dp[slen+1][plen+1];

    return isMatchAux(s, slen, p, plen, (bool *)dp);
}

static bool
isMatchAux(char *s, int slen, char *p, int plen, bool *dp)
{
    if (plen == 0) {
        return slen == 0;
    }

    if (slen && (p[plen-1] == '.' || p[plen-1] == s[slen-1])) {
        dp[slen*plen + plen] = isMatchAux(s, slen-1, p, plen-1, dp);
    } else if (p[plen-1] == '*') {
        dp[slen*plen + plen] = isMatchAux(s, slen, p, plen-2, dp);

        if (slen && (p[plen-2] == '.' || p[plen-2] == s[slen-1])) {
            dp[slen*plen + plen] = dp[slen*plen + plen]
                || isMatchAux(s, slen-1, p, plen, dp);
        }
    } else {
        dp[slen*plen + plen] = false;
    }

    return dp[slen*plen + plen];
}

bool
isMatchDPBottomUp(char *s, char *p)
{
    int i, j, slen, plen;

    slen = strlen(s);
    plen = strlen(p);

    bool dp[slen+1][plen+1];

    for (i = 0; i <= slen; i++) {
        for (j = 0; j <= plen; j++) {
            if (j == 0) {
                dp[i][j] = i == 0;
                continue;
            }

            if (i == 0) {
                dp[i][j] = p[j-1] == '*'
                    ? dp[i][j-2]
                    : false;
                continue;
            }

            if (p[j-1] == '.' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
                continue;
            }

            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];

                if (!dp[i][j] && dp[i-1][j]) {
                    dp[i][j] = (p[j-2] == '.' || s[i-1] == p[j-2]);
                }
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[slen][plen];
}

