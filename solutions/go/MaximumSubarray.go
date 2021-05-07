func maxSubArray(nums []int) int {
	maxSoFar, maxEndHere := nums[0], nums[0]

	for i := 1; i < len(nums); i++ {
		maxEndHere = max(nums[i]+maxEndHere, nums[i])
		maxSoFar = max(maxSoFar, maxEndHere)
	}

	return maxSoFar
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

