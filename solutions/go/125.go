func isPalindrome(s string) bool {
	for i, j := 0, len(s)-1; i < j; /* empty */ {
		if isAlnum(s[i]) && isAlnum(s[j]) {
			if toLower(s[i]) == toLower(s[j]) {
				i++
				j--
			} else {
				return false
			}
		} else if !isAlnum(s[i]) {
			i++
		} else if !isAlnum(s[j]) {
			j--
		} else {
			i++
			j--
		}
	}

	return true
}

func isAlnum(b byte) bool {
	if (b >= '0' && b <= '9') || (b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z') {
		return true
	}

	return false
}

func toLower(b byte) byte {
	if b >= 'A' && b <= 'Z' {
		return b + 'a' - 'A'
	}

	return b
}
