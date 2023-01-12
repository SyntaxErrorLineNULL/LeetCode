package problem1443

func minTime(n int, edges [][]int, hasApple []bool) int {
	parentEdge := make([]int, n)
	for i := 0; i < n; i++ {
		parentEdge[i] = -1
	}
	for i := 0; i < n-1; i++ {
		if parentEdge[edges[i][1]] == -1 {
			parentEdge[edges[i][1]] = edges[i][0]
		} else {
			parentEdge[edges[i][0]] = edges[i][1]
		}
	}

	result := 0
	for i := 0; i < n; i++ {
		if !hasApple[i] {
			continue
		}

		for node := i; parentEdge[node] != -1; result++ {
			parentNode := parentEdge[node]
			parentEdge[node] = -1
			node = parentNode
		}
	}
	return result * 2
}
