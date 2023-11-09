func isSubsequence(s string, t string) bool {
	if len(s) > len(t) {
		return false
	}

	var idx int

	for i := 0; i < len(t); i++ {
		if idx < len(s) && s[idx] == t[i] {
			idx++
		}
	}

	return idx == len(s)
}
