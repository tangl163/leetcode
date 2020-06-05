#define max(a, b) ((a) > (b) ? (a) : (b))

int
longestPalindromeSubseq(char *s)
{
    int i, j, k, len;

    len = strlen(s);
    if (len == 0) {
        return 0;
    }

    int dp[len][len];

    for (i = 0; i < len; i++) {
        dp[i][i] = 1;
    }

    for (i = 2; i <= len; i++) {
        for (j = 0; i+j <= len; j++) {
            k = j + i - 1;
            if (i == 2 && s[j] == s[k]) {
                dp[j][k] = 2;
            } else if (s[j] == s[k]) {
                dp[j][k] = dp[j+1][k-1] + 2;
            } else {
                dp[j][k] = max(dp[j][k-1], dp[j+1][k]);
            }
        }
    }

    return dp[0][len-1];
}

