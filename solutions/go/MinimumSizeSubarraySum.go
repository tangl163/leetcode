import (
	"math"
)

func minSubArrayLen(target int, nums []int) int {
	var i, j, sum int

	length := len(nums)
	min := math.MaxInt32

	for j < length {
		sum += nums[j]
		j++

		for sum >= target {
			tmp := j - i
			if tmp < min {
				min = tmp
			}

			sum -= nums[i]
			i++
		}
	}

	if min == math.MaxInt32 {
		return 0
	}

	return min
}
