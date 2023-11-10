func wordPattern(pattern string, s string) bool {
	tokens := strings.Fields(s)

	if len(pattern) != len(tokens) {
		return false
	}

	h1 := make(map[byte]byte)
	h2 := make(map[string]byte)

	for i := 0; i < len(pattern); i++ {
		idx1, ok1 := h1[pattern[i]]
		idx2, ok2 := h2[tokens[i]]
		if ok1 != ok2 || idx1 != idx2 {
			return false
		}

		h1[pattern[i]] = byte(i)
		h2[tokens[i]] = byte(i)
	}

	return true
}
