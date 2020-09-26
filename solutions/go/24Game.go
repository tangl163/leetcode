import "math"

const PRECISENESS = 1e-6

func judgePoint24(nums []int) bool {
	arr := make([]float64, len(nums))
	for i, val := range nums {
		arr[i] = float64(val)
	}

	return aux(arr)
}

func aux(arr []float64) bool {
	length := len(arr)
	if length == 1 {
		if math.Abs(arr[0] - 24) < PRECISENESS {
			return true
		}

		return false
	}

	for i := 0; i < length-1; i++ {
		for j := i+1; j < length; j++ {
			tmp := make([]float64, length-1)

			for k , s := 0, 0; k < length; k++ {
				if k != i && k != j {
					tmp[s] = arr[k]
					s++
				}
			}

			arithmetic := possibleArithmetic(arr[i], arr[j])
			for _, ret := range arithmetic {
				tmp[length-2] = ret
				if aux(tmp) {
					return true
				}
			}
		}
	}

	return false
}

func possibleArithmetic(a, b float64) []float64 {
	var ret []float64

	ret = append(ret, a + b, a * b, a - b, b - a)

	if math.Abs(a) > PRECISENESS {
		ret = append(ret, b / a)
	}

	if math.Abs(b) > PRECISENESS {
		ret = append(ret, a / b)
	}

	return ret
}
