package problem149

import "math"

func maxPoints(points [][]int) int {
	if len(points) <= 2 {
		return len(points)
	}
	max := 0
	for x := 0; x < len(points); x++ {
		for y := x + 1; y < len(points); y++ {
			count := 2
			for c := 0; c < len(points); c++ {
				if c != x && c != y {
					if (points[y][1]-points[x][1])*(points[x][0]-points[c][0]) ==
						(points[x][1]-points[c][1])*(points[y][0]-points[x][0]) {
						count++
					}
				}
			}
			max = int(math.Max(float64(max), float64(count)))
		}
	}

	return max
}
