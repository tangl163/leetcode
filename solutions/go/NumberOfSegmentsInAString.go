import "unicode"

func countSegments(s string) int {
	var n int
	sign := true

	for _, c := range s {
		if unicode.IsSpace(c) {
			sign = true
		} else if sign {
			n++
			sign = false
		}
	}

	return n
}

