bool
isMatch(char *s, char *p)
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
                dp[i][j] = p[j-1] == '*' ?
                    dp[i][j-1] : false;
                continue;
            }

            if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[slen][plen];
}

