func canJump(nums []int) bool {
	maxReach := 0

	for i := 0; i <= maxReach; i++ {
		if tmp := nums[i] + i; tmp > maxReach {
			maxReach = tmp
		}

		if maxReach >= len(nums)-1 {
			return true
		}
	}

	return false
}

