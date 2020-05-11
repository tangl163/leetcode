func canJump(nums []int) bool {
	if len(nums) <= 1 {
		return true
	}

	if nums[0] == 0 {
		return false
	}

	step := nums[0]
	maxReach := nums[0]

	for i := 1; i < len(nums); i++ {
		if maxReach >= len(nums)-1 {
			return true
		}

		step--
		if maxReach < i+nums[i] {
			maxReach = i + nums[i]
		}

		if step == 0 {
			if i >= maxReach {
				return false
			}

			step = maxReach - i
		}
	}

	return false
}

