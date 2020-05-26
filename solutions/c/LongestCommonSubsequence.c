#define max(a, b) ((a) > (b) ? (a) : (b))

int
longestCommonSubsequence(char *x, char *y)
{
    int i, j, xlen, ylen;

    xlen = strlen(x);
    ylen = strlen(y);

    int c[xlen+1][ylen+1];

    for (i = 0; i <= xlen; i++) {
        for (j = 0; j <= ylen; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
                continue;
            }

            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    return c[xlen][ylen];
}

