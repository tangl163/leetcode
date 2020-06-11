func findMedianSortedArrays(x, y []int) float64 {
	var median float64

	lenx, leny := len(x), len(y)
	if lenx > leny {
		return findMedianSortedArrays(y, x)
	}

	low, high := 0, lenx

	for low <= high {
		pivotx := (low + high) / 2
		pivoty := (lenx + leny + 1) / 2 - pivotx

		leftx, rightx := math.MinInt32, math.MaxInt32
		lefty, righty := math.MinInt32, math.MaxInt32

		if pivotx != 0 {
			leftx = x[pivotx-1]
		}

		if pivotx != lenx {
			rightx = x[pivotx]
		}

		if pivoty != 0 {
			lefty = y[pivoty-1]
		}

		if pivoty != leny {
			righty = y[pivoty]
		}

		if leftx <= righty && lefty <= rightx {
			if (lenx + leny) & 1 == 1 {
				median = float64(max(leftx, lefty))
			} else {
				median = float64(max(leftx, lefty) + min(rightx, righty)) / 2
			}

			break
		} else if leftx > righty {
			high = pivotx - 1
		} else {
			low = pivotx + 1
		}
	}

	return median
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

