func lengthOfLIS(arr []int) int {
	if len(arr) == 0 {
		return 0
	}

	dp := make([]int, len(arr))
	dp[0] = 1
	max := 1

	for i := 1; i < len(arr); i++ {
		tmp := 1
		for j := 0; j < i; j++ {
			if arr[i] > arr[j] && dp[j] >= tmp {
				tmp = dp[j] + 1
			}
		}

		dp[i] = tmp

		if tmp > max {
			max = tmp
		}
	}

	return max
}

