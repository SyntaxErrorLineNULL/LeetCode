package problem452

import (
	"sort"
)

func findMinArrowShots(points [][]int) int {
	arrow := 1
	sort.Slice(points, func(i, j int) bool {
		return points[i][1] < points[j][1]
	})
	point := points[0][1]

	for i := 0; i < len(points); i++ {
		if points[i][0] > point {
			arrow++
			point = points[i][1]
		}
	}

	return arrow
}
