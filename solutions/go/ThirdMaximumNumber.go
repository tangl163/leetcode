import "math"

func thirdMax(nums []int) int {
	var a, b, c int

	a, b, c = math.MinInt64, math.MinInt64, math.MinInt64

	for _, v := range nums {
		if v <= a || v == b || v == c {
			continue
		}

		if v > c {
			a, b, c = b, c, v
		} else if v > b {
			a, b = b, v
		} else {
			a = v
		}
	}

	if a == math.MinInt64 {
		return c
	}

	return a
}
