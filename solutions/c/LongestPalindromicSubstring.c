char *
longestPalindrome(char *s)
{
    char *p;
    int i, j, k, maxLen, start, len;

    len = strlen(s);
    if (len == 0) {
        return "";
    }

    bool dp[len][len];

    for (i = 0; i < len; i++) {
        dp[i][i] = true;
    }

    start = 0;
    maxLen = 1;

    for (i = 2; i <= len; i++) {
        for (j = 0; j+i <= len; j++) {
            k = j + i - 1;
            if (i == 2 && s[j] == s[k]) {
                dp[j][k] = true;
                start = j;
                maxLen = 2;
            } else if (s[j] == s[k] && dp[j+1][k-1]) {
                dp[j][k] = true;
                if (i > maxLen) {
                    start = j;
                    maxLen = i;
                }
            } else {
                dp[j][k] = false;
            }
        }
    }

    return strndup(s+start, maxLen);
}

