package problem4

import "sort"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	nums1 = append(nums1, nums2...)
	sort.Ints(nums1)

	if len(nums1)%2 == 0 {
		left := float64(nums1[(len(nums1)/2)-1])
		right := float64(nums1[(len(nums1) / 2)])
		return (left + right) / 2
	}

	var median float64
	median = float64(nums1[len(nums1)/2])
	return median
}
