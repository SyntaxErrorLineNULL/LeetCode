package problem26

func removeDuplicates(nums []int) int {
	nextIndex := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1] {
			nums[nextIndex] = nums[i]
			nextIndex++
		}
	}

	return nextIndex
}
