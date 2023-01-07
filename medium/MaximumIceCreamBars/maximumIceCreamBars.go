package problem1833

import "sort"

func maxIceCream(costs []int, coins int) int {
	sort.Ints(costs)
	count := 0

	for i := 0; i < len(costs); i++ {
		coins -= costs[i]
		if coins < 0 {
			break
		}
		count++
	}

	return count
}
