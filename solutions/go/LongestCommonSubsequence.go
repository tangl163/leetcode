func longestCommonSubsequence(x, y string) int {
	xlen, ylen := len(x), len(y)

	c := make([][]int, xlen+1)

	for i := 0; i <= xlen; i++ {
		c[i] = make([]int, ylen+1)
	}

	for i := 1; i <= xlen; i++ {
		for j := 1; j <= ylen; j++ {
			if x[i-1] == y[j-1] {
				c[i][j] = c[i-1][j-1] + 1
			} else if c[i-1][j] > c[i][j-1] {
				c[i][j] = c[i-1][j]
			} else {
				c[i][j] = c[i][j-1]
			}
		}
	}

	return c[xlen][ylen]
}

