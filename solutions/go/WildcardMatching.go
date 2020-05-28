func isMatch(s string, p string) bool {
	dp := make([][]bool, len(s)+1)

	for i := 0; i <= len(s); i++ {
		dp[i] = make([]bool, len(p)+1)
	}

	for i := 0; i <= len(s); i++ {
		for j := 0; j <= len(p); j++ {
			if j == 0 {
				dp[i][j] = i == 0
				continue
			}

			if i == 0 {
				if p[j-1] == '*' {
					dp[i][j] = dp[i][j-1]
				} else {
					dp[i][j] = false
				}
				continue
			}

			if p[j-1] == '?' || p[j-1] == s[i-1] {
				dp[i][j] = dp[i-1][j-1]
			} else if p[j-1] == '*' {
				dp[i][j] = dp[i][j-1] || dp[i-1][j]
			} else {
				dp[i][j] = false
			}
		}
	}

	return dp[len(s)][len(p)]
}
