import "sort"

func threeSum(nums []int) [][]int {
	var ret [][]int
	if len(nums) < 3 {
		return ret
	}

	sort.Ints(nums)

	for i := 0; i < len(nums) - 3; i++ {
		if nums[i] > 0 {
			break
		}

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		left := -nums[i]
		for j, k := i+1, len(nums)-1; j < k; {
			target := nums[j] + nums[k]

			if target < left {
				j++
			} else if target > left {
				k--
			} else {
				ret = append(ret, []int{nums[i], nums[j], nums[k]})

				for j++; j < k && nums[j] == nums[j-1]; j++ {
				}

				for k--; k > j && nums[k] == nums[k+1]; k-- {
				}
			}
		}
	}

	return ret
}
