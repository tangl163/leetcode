int
lengthOfLIS(int *arr, int n)
{
    int i, j, max, tmp;

    if (n <= 1) {
        return n;
    }

    int dp[n];
    max = dp[0] = 1;

    for (i = 1; i < n; i++) {
        tmp = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j] >= tmp) {
                tmp = dp[j] + 1;
            }
        }

        dp[i] = tmp;

        if (tmp > max) {
            max = tmp;
        }
    }

    return max;
}

