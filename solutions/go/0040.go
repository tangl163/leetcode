// https://leetcode.com/problems/combination-sum-ii/

package golang

import (
	"sort"
)

func combinationSum2(candidates []int, target int) (res [][]int) {
	n := len(candidates)
	sort.Ints(candidates)
	var backtrack func(start, prevSum int, prevList []int)
	backtrack = func(start, prevSum int, prevList []int) {
		if prevSum == target {
			res = append(res, prevList)
			return
		}
		for i := start; i < n; i++ {
			if v := prevSum + candidates[i]; v > target {
				return
			} else {
				if i > start && candidates[i] == candidates[i-1] {
					continue
				}
				backtrack(i+1, v, append(prevList, candidates[i]))
			}
		}
	}
	backtrack(0, 0, []int{})
	return
}
