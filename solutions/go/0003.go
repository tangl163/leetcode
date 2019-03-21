// https://leetcode.com/problems/longest-substring-without-repeating-characters

package golang

func lengthOfLongestSubstring(s string) int {
	var result int
	var hashMap = make(map[byte]int)

	for i, j := 0, 0; i < len(s); i++ {
		if k, ok := hashMap[s[i]]; ok && k > j {
			j = k
		}
		if v := i - j + 1; v > result {
			result = v
		}
		hashMap[s[i]] = i + 1
	}

	return result
}
