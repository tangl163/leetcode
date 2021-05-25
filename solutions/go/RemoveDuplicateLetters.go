func removeDuplicateLetters(s string) string {
	var ret []byte
	visited := make([]bool, 26)
	freq := make([]byte, 26)

	for _, char := range s {
		freq[char-'a']++
	}

	for _, char := range s {
		freq[char-'a']--

		if visited[char-'a'] {
			continue
		}

		for size := len(ret); size != 0 && byte(char) < ret[size-1] && freq[ret[size-1]-'a'] != 0; size = len(ret) {
			visited[ret[size-1]-'a'] = false
			ret = ret[:size-1]
		}

		ret = append(ret, byte(char))
		visited[char-'a'] = true
	}

	return string(ret)
}
