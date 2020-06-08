func strStr(haystack string, needle string) int {
	len1, len2 := len(haystack), len(needle)
	if len2 == 0 {
		return 0
	}

	t := kmpAux(needle)

	for i, j := 0, 0; i < len1; i++ {
		for j > 0 && haystack[i] != needle[j] {
			j = t[j-1]
		}

		if haystack[i] == needle[j] {
			j++
		}

		if j == len2 {
			return i - j + 1
		}
	}

	return -1
}

func kmpAux(needle string) []int {
	t := make([]int, len(needle))

	for i, j := 1, 0; i < len(needle); i++ {
		for j > 0 && needle[i] != needle[j] {
			j = t[j-1]
		}

		if needle[i] == needle[j] {
			j++;
		}

		t[i] = j
	}

	return t
}

