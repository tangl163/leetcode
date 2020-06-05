func longestPalindrome(s string) string {
	length := len(s)
	if length == 0 {
		return s
	}

	start, maxLen := 0, 1

	dp := make([][]bool, length)
	for i := 0; i < length; i++ {
		dp[i] = make([]bool, length)
		dp[i][i] = true
	}

	for i := 2; i <= length; i++ {
		for j := 0; i+j <= length; j++ {
			k := j + i - 1
			if i == 2 && s[j] == s[k] {
				dp[j][k] = true
				start, maxLen = j, i
			} else if s[j] == s[k] && dp[j+1][k-1] {
				dp[j][k] = true
				if i > maxLen {
					start, maxLen = j, i
				}
			} else {
				dp[j][k] = false
			}
		}
	}

	return s[start : start+maxLen]
}

