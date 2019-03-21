// https://leetcode.com/problems/two-sum

package golang

func twoSum(nums []int, target int) []int {
	var hashMap = make(map[int]int)
	for idx, num := range nums {
		another := target - num
		if v, ok := hashMap[another]; ok {
			return []int{v, idx}
		}
		hashMap[num] = idx
	}
	panic("No two sum solution")
}
