func isIsomorphic(s string, t string) bool {
	dict := make(map[byte]byte, len(s))
	used := make(map[byte]bool, len(t))

	for i := 0; i < len(s); i++ {
		if v, ok := dict[s[i]]; ok {
			if v != t[i] {
				return false
			}
		} else {
			if used[t[i]] {
				return false
			}

			dict[s[i]] = t[i]
			used[t[i]] = true
		}
	}

	return true
}
