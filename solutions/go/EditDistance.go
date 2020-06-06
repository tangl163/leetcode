func minDistance(x, y string) int {
	xlen, ylen := len(x), len(y)
	dp := make([][]int, xlen+1)

	for i := 0; i <= xlen; i++ {
		dp[i] = make([]int, ylen+1)
	}

	for i := 0; i <= xlen; i++ {
		for j := 0; j <= ylen; j++ {
			if i == 0 || j == 0 {
				if i == 0 {
					dp[i][j] = j
				} else {
					dp[i][j] = i
				}
			} else if x[i-1] == y[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])
			}
		}
	}

	return dp[xlen][ylen]
}

func min(a, b, c int) int {
	if a < b && a < c {
		return a
	} else if b < c {
		return b
	} else {
		return c
	}
}

