#define min(a, b) ((a) < (b) ? (a) : (b))

int
minDistance(char *x, char *y)
{
    int i, j, xlen, ylen;

    xlen = strlen(x);
    ylen = strlen(y);

    int dp[xlen+1][ylen+1];

    for (i = 0; i <= xlen; i++) {
        for (j = 0; j <= ylen; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = i == 0 ? j : i;
            } else if (x[i-1] == y[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
    }

    return dp[xlen][ylen];
}

