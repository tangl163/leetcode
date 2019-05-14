package golang

import (
	"reflect"
	"testing"
)

func Test0040(t *testing.T) {
	var args = map[int][]int{
		8: {10, 1, 2, 7, 6, 1, 5},
	}
	var result = map[int][][]int{
		8: {
			{1, 1, 6},
			{1, 2, 5},
			{1, 7},
			{2, 6},
		},
	}
	for target, candidates := range args {
		res := combinationSum2(candidates, target)
		if !reflect.DeepEqual(res, result[target]) {
			t.Errorf("unexpected result, expect = %v, but = %v", result[target], res)
		}
	}
}
