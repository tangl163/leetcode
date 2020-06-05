func longestPalindromeSubseq(s string) int {
	l := len(s)
	if l == 0 {
		return 0
	}

	dp := make([][]int, l)
	for i := 0; i < l; i++ {
		dp[i] = make([]int, l)
		dp[i][i] = 1
	}

	for i := 2; i <= l; i++ {
		for j := 0; j+i <= l; j++ {
			k := j + i - 1
			if i == 2 && s[j] == s[k] {
				dp[j][k] = 2
			} else if s[j] == s[k] {
				dp[j][k] = dp[j+1][k-1] + 2
			} else if dp[j][k-1] > dp[j+1][k] {
				dp[j][k] = dp[j][k-1]
			} else {
				dp[j][k] = dp[j+1][k]
			}
		}
	}

	return dp[0][l-1]
}

