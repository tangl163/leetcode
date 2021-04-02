func findKthLargest(nums []int, k int) int {
	pivot := partition(nums)

	if pivot < k-1 {
		return findKthLargest(nums[pivot+1:], k-pivot-1)
	} else if pivot > k-1 {
		return findKthLargest(nums[:pivot], k)
	} else {
		return nums[pivot]
	}
}

func partition(arr []int) int {
	length := len(arr)

	last := 0
	swap(arr, 0, length/2)

	for i := 1; i < length; i++ {
		if arr[i] > arr[0] {
			last++
			swap(arr, i, last)
		}
	}

	swap(arr, 0, last)

	return last
}

func swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}
