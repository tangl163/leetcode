func jump(nums []int) int {
	var step, cur, maxReach int

	for i := 0; i < len(nums)-1; i++ {
		if tmp := nums[i] + i; tmp > maxReach {
			maxReach = tmp
		}

		if cur == i {
			step++
			cur = maxReach
		}
	}

	return step
}
